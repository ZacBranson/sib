/*
 * © Copyright IBM Corporation 2020.
 *
 * LICENSE: Apache License 2.0 (Apache-2.0)
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 */

#ifndef SIB_OPTIMIZER_SPARSE_H
#define SIB_OPTIMIZER_SPARSE_H

#include <stdint.h>

class SIBOptimizerInteger {
    public:
        SIBOptimizerSparse(int32_t n_clusters, int32_t n_features, int32_t n_samples,
                           const int64_t *xy, int64_t xy_sum, const int64_t *x_sum);
        virtual ~SIBOptimizerSparse();
n_clusters, n_features, n_samples, xy, xy_sum, x_sum
        void iterate(
            bool clustering_mode, // clustering / classification mode:
            // data to cluster / classify:
            int32_t n_samples, const int32_t *xy_indices, const int32_t *xy_indptr,
            const int64_t *xy_data, int64_t sum_xy, const int64_t* sum_x,
            int32_t* x_permutation,   // order of iteration:
            // current clusters:
            int32_t *t_size, int64_t *sum_t, int64_t *cent_sum_t,
            // assigned labels and costs:
            int32_t *labels, double* costs, double* total_cost,
            // stats on updates:
            double* ity, double* ht, double* change_rate);

    private:
        int32_t n_clusters;
        int32_t n_features;
};

#endif
