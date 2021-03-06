/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2009 Soeren Sonnenburg
 * Written (W) 1999-2008 Gunnar Raetsch
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _COMBINEDKERNEL_H___
#define _COMBINEDKERNEL_H___

#include "lib/List.h"
#include "lib/io.h"
#include "kernel/Kernel.h"

#include "features/Features.h"
#include "features/CombinedFeatures.h"

namespace shogun
{
class CFeatures;
class CCombinedFeatures;
class CList;
class CListElement;
/**
 * @brief The Combined kernel is used to combine a number of kernels into a
 * single CombinedKernel object by linear combination.
 *
 * It keeps pointers to the added sub-kernels \f$k_m({\bf x}, {\bf x'})\f$ and
 * for each sub-kernel - a kernel specific weight \f$\beta_m\f$.
 *
 * It is especially useful to combine kernels working on different domains and
 * to combine kernels looking at independent features and requires
 * CCombinedFeatures to be used.
 *
 * It is defined as:
 *
 * \f[
 *     k_{combined}({\bf x}, {\bf x'}) = \sum_{m=1}^M \beta_m k_m({\bf x}, {\bf x'})
 * \f]
 *
 */
class CCombinedKernel : public CKernel
{
	public:
		/** constructor
		 *
		 * @param size cache size
		 * @param append_subkernel_weights if subkernel weights shall be
		 *        appended
		 */
		CCombinedKernel(int32_t size=10, bool append_subkernel_weights=false);

		virtual ~CCombinedKernel();

		/** initialize kernel
		 *
		 * @param lhs features of left-hand side
		 * @param rhs features of right-hand side
		 * @return if initializing was successful
		 */
		virtual bool init(CFeatures* lhs, CFeatures* rhs);

		/** clean up kernel */
		virtual void cleanup();

		/** return what type of kernel we are
		 *
		 * @return kernel type COMBINED
		 */
		virtual EKernelType get_kernel_type()
		{
			return K_COMBINED;
		}

		/** return feature type the kernel can deal with
		 *
		 * @return feature type UNKNOWN
		 */
		virtual EFeatureType get_feature_type()
		{
			return F_UNKNOWN;
		}

		/** return feature class the kernel can deal with
		 *
		 * @return feature class COMBINED
		 */
		virtual EFeatureClass get_feature_class()
		{
			return C_COMBINED;
		}

		/** return the kernel's name
		 *
		 * @return name Combined
		 */
		virtual const char* get_name() const { return "CombinedKernel"; }

		/** list kernels */
		void list_kernels();

		/** get first kernel
		 *
		 * @return first kernel
		 */
		inline CKernel* get_first_kernel()
		{
			return (CKernel*) kernel_list->get_first_element();
		}

		/** get first kernel
		 *
		 * @param current
		 * @return first kernel
		 */
		inline CKernel* get_first_kernel(CListElement*& current)
		{
			return (CKernel*) kernel_list->get_first_element(current);
		}

		/** get kernel
		 *
		 * @param idx index of kernel
		 * @return kernel at index idx
		 */
		inline CKernel* get_kernel(int32_t idx)
		{
			CKernel * k = get_first_kernel();
			for (int32_t i=0; i<idx; i++)
			{
				SG_UNREF(k);
				k = get_next_kernel();
			}
			return k;
		}

		/** get last kernel
		 *
		 * @return last kernel
		 */
		inline CKernel* get_last_kernel()
		{
			return (CKernel*) kernel_list->get_last_element();
		}

		/** get next kernel
		 *
		 * @return next kernel
		 */
		inline CKernel* get_next_kernel()
		{
			return (CKernel*) kernel_list->get_next_element();
		}

		/** get next kernel multi-thread safe
		 *
		 * @param current
		 * @return next kernel
		 */
		inline CKernel* get_next_kernel(CListElement*& current)
		{
			return (CKernel*) kernel_list->get_next_element(current);
		}

		/** insert kernel
		 *
		 * @param k kernel
		 * @return if inserting was successful
		 */
		inline bool insert_kernel(CKernel* k)
		{
			ASSERT(k);
			adjust_num_lhs_rhs_initialized(k);

			if (!(k->has_property(KP_LINADD)))
				unset_property(KP_LINADD);

			return kernel_list->insert_element(k);
		}

		/** append kernel
		 *
		 * @param k kernel
		 * @return if appending was successful
		 */
		inline bool append_kernel(CKernel* k)
		{
			ASSERT(k);
			adjust_num_lhs_rhs_initialized(k);

			if (!(k->has_property(KP_LINADD)))
				unset_property(KP_LINADD);

			return kernel_list->append_element(k);
		}


		/** delete kernel
		 *
		 * @return if deleting was successful
		 */
		inline bool delete_kernel()
		{
			CKernel* k=(CKernel*) kernel_list->delete_element();
			SG_UNREF(k);

			if (!k)
			{
				num_lhs=0;
				num_rhs=0;
			}

			return (k!=NULL);
		}

		/** check if subkernel weights are appended
		 *
		 * @return if subkernel weigths are appended
		 */
		inline bool get_append_subkernel_weights()
		{
			return append_subkernel_weights;
		}

		/** get number of subkernels
		 *
		 * @return number of subkernels
		 */
		inline int32_t get_num_subkernels()
		{
			if (append_subkernel_weights)
			{
				int32_t num_subkernels = 0 ;
				CListElement* current = NULL ;
				CKernel * k = get_first_kernel(current) ;

				while(k)
				{
					num_subkernels += k->get_num_subkernels() ;
					SG_UNREF(k);
					k = get_next_kernel(current) ;
				}
				return num_subkernels ;
			}
			else
				return kernel_list->get_num_elements();
		}

		/** test whether features have been assigned to lhs and rhs
		 *
		 * @return true if features are assigned
		 */
		virtual inline bool has_features()
		{
			return initialized;
		}

		/** remove lhs from kernel */
		virtual void remove_lhs();

		/** remove rhs from kernel */
		virtual void remove_rhs();

		/** remove lhs and rhs from kernel */
		virtual void remove_lhs_and_rhs();

		/** initialize optimization
		 *
		 * @param count count
		 * @param IDX index
		 * @param weights weights
		 * @return if initializing was successful
		 */
		virtual bool init_optimization(
			int32_t count, int32_t *IDX, float64_t * weights);

		/** delete optimization
		 *
		 * @return if deleting was successful
		 */
		virtual bool delete_optimization();

		/** compute optimized
		 *
		 * @param idx index to compute
		 * @return optimized value at given index
		 */
		virtual float64_t compute_optimized(int32_t idx);

		/** computes output for a batch of examples in an optimized fashion (favorable if kernel supports it,
		 * i.e. has KP_BATCHEVALUATION.
		 * to the outputvector target (of length num_vec elements) the output for the examples enumerated
		 * in vec_idx are added. therefore make sure that it is initialized with ZERO. the following num_suppvec,
		 * IDX, alphas arguments are the number of support vectors, their indices and weights
		 */
		virtual void compute_batch(
			int32_t num_vec, int32_t* vec_idx, float64_t* target,
			int32_t num_suppvec, int32_t* IDX, float64_t* alphas,
			float64_t factor=1.0);

		/** helper for compute optimized kernel
		 *
		 * @param p thread parameter
		 */
		static void* compute_optimized_kernel_helper(void* p);

		/** helper for compute kernel
		 *
		 * @param p thread parameter
		 */
		static void* compute_kernel_helper(void* p);

		/** emulates batch computation, via linadd optimization w^t x or even down to sum_i alpha_i K(x_i,x)
		 *
		 * @param k kernel
		 * @param num_vec number of vectors
		 * @param vec_idx vector index
		 * @param target target
		 * @param num_suppvec number of support vectors
		 * @param IDX IDX
		 * @param weights weights
		 */
		void emulate_compute_batch(
			CKernel* k, int32_t num_vec, int32_t* vec_idx, float64_t* target,
			int32_t num_suppvec, int32_t* IDX, float64_t* weights);

		/** add to normal vector
		 *
		 * @param idx where to add
		 * @param weight what to add
		 */
		virtual void add_to_normal(int32_t idx, float64_t weight);

		/** clear normal vector */
		virtual void clear_normal();

		/** compute by subkernel
		 *
		 * @param idx index
		 * @param subkernel_contrib subkernel contribution
		 */
		virtual void compute_by_subkernel(
			int32_t idx, float64_t * subkernel_contrib);

		/** get subkernel weights
		 *
		 * @param num_weights where number of weights is stored
		 * @return subkernel weights
		 */
		virtual const float64_t* get_subkernel_weights(int32_t& num_weights);

		/** get subkernel weights (swig compatible)
		 *
		 * @param weights subkernel weights
		 * @param num_weights number of weights
		 */
		virtual void get_subkernel_weights(float64_t** weights, int32_t* num_weights);

		/** set subkernel weights
		 *
		 * @param weights new subkernel weights
		 * @param num_weights number of subkernel weights
		 */
		virtual void set_subkernel_weights(
			float64_t* weights, int32_t num_weights);

		/** set optimization type
		 *
		 * @param t optimization type
		 */
		virtual void set_optimization_type(EOptimizationType t);

		/** precompute all sub-kernels */
		bool precompute_subkernels();

	protected:
		/** compute kernel function
		 *
		 * @param x x
		 * @param y y
		 * @return computed kernel function
		 */
		virtual float64_t compute(int32_t x, int32_t y);

		/** adjust the variables num_lhs, num_rhs and initialized
		 * based on the kernel to be appended/inserted 
		 *
		 * @param k kernel
		 */
		inline void adjust_num_lhs_rhs_initialized(CKernel* k)
		{
			ASSERT(k);

			if (k->get_num_vec_lhs())
			{
				if (num_lhs)
					ASSERT(num_lhs==k->get_num_vec_lhs());
				num_lhs=k->get_num_vec_lhs();

				if (!get_num_subkernels())
				{
					initialized=true;
#ifdef USE_SVMLIGHT
					cache_reset();
#endif //USE_SVMLIGHT
				}
			}
			else
				initialized=false;

			if (k->get_num_vec_rhs())
			{
				if (num_rhs)
					ASSERT(num_rhs==k->get_num_vec_rhs());
				num_rhs=k->get_num_vec_rhs();

				if (!get_num_subkernels())
				{
					initialized=true;
#ifdef USE_SVMLIGHT
					cache_reset();
#endif //USE_SVMLIGHT
				}
			}
			else
				initialized=false;
		}

	private:
		void init();

	protected:
		/** list of kernels */
		CList* kernel_list;
		/** support vector count */
		int32_t   sv_count;
		/** support vector index */
		int32_t*  sv_idx;
		/** support vector weights */
		float64_t* sv_weight;
		/** subkernel weights buffers */
		float64_t* subkernel_weights_buffer;
		/** if subkernel weights are appended */
		bool append_subkernel_weights;
		/** whether kernel is ready to be used */
		bool initialized;
};
}
#endif /* _COMBINEDKERNEL_H__ */
