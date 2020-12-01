// Generated by rstantools.  Do not edit by hand.

/*
    reacttemporal2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    reacttemporal2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with reacttemporal2.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_b_splines_actual_phe_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_b_splines_actual_phe");
    reader.add_event(78, 76, "end", "model_b_splines_actual_phe");
    return reader;
}
template <typename T0__, typename T1__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__>::type, Eigen::Dynamic, 1>
build_b_spline(const std::vector<T0__>& t,
                   const std::vector<T1__>& ext_knots,
                   const int& ind,
                   const int& order, std::ostream* pstream__);
template <typename T0__, typename T1__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__>::type, Eigen::Dynamic, 1>
build_b_spline(const std::vector<T0__>& t,
                   const std::vector<T1__>& ext_knots,
                   const int& ind,
                   const int& order, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 9;
        validate_non_negative_index("b_spline", "size(t)", size(t));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> b_spline(size(t));
        stan::math::initialize(b_spline, DUMMY_VAR__);
        stan::math::fill(b_spline, DUMMY_VAR__);
        current_statement_begin__ = 10;
        validate_non_negative_index("w1", "size(t)", size(t));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> w1(size(t));
        stan::math::initialize(w1, DUMMY_VAR__);
        stan::math::fill(w1, DUMMY_VAR__);
        stan::math::assign(w1,rep_vector(0, size(t)));
        current_statement_begin__ = 11;
        validate_non_negative_index("w2", "size(t)", size(t));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> w2(size(t));
        stan::math::initialize(w2, DUMMY_VAR__);
        stan::math::fill(w2, DUMMY_VAR__);
        stan::math::assign(w2,rep_vector(0, size(t)));
        current_statement_begin__ = 12;
        if (as_bool(logical_eq(order, 1))) {
            current_statement_begin__ = 13;
            for (int i = 1; i <= size(t); ++i) {
                current_statement_begin__ = 14;
                stan::model::assign(b_spline, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (primitive_value(logical_lte(get_base1(ext_knots, ind, "ext_knots", 1), get_base1(t, i, "t", 1))) && primitive_value(logical_lt(get_base1(t, i, "t", 1), get_base1(ext_knots, (ind + 1), "ext_knots", 1)))), 
                            "assigning variable b_spline");
            }
        } else {
            current_statement_begin__ = 16;
            if (as_bool(logical_neq(get_base1(ext_knots, ind, "ext_knots", 1), get_base1(ext_knots, ((ind + order) - 1), "ext_knots", 1)))) {
                current_statement_begin__ = 17;
                stan::math::assign(w1, divide(subtract(to_vector(t), rep_vector(get_base1(ext_knots, ind, "ext_knots", 1), size(t))), (get_base1(ext_knots, ((ind + order) - 1), "ext_knots", 1) - get_base1(ext_knots, ind, "ext_knots", 1))));
            }
            current_statement_begin__ = 19;
            if (as_bool(logical_neq(get_base1(ext_knots, (ind + 1), "ext_knots", 1), get_base1(ext_knots, (ind + order), "ext_knots", 1)))) {
                current_statement_begin__ = 20;
                stan::math::assign(w2, subtract(1, divide(subtract(to_vector(t), rep_vector(get_base1(ext_knots, (ind + 1), "ext_knots", 1), size(t))), (get_base1(ext_knots, (ind + order), "ext_knots", 1) - get_base1(ext_knots, (ind + 1), "ext_knots", 1)))));
            }
            current_statement_begin__ = 23;
            stan::math::assign(b_spline, add(elt_multiply(w1, build_b_spline(t, ext_knots, ind, (order - 1), pstream__)), elt_multiply(w2, build_b_spline(t, ext_knots, (ind + 1), (order - 1), pstream__))));
        }
        current_statement_begin__ = 26;
        return stan::math::promote_scalar<fun_return_scalar_t__>(b_spline);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct build_b_spline_functor__ {
    template <typename T0__, typename T1__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__>::type, Eigen::Dynamic, 1>
    operator()(const std::vector<T0__>& t,
                   const std::vector<T1__>& ext_knots,
                   const int& ind,
                   const int& order, std::ostream* pstream__) const {
        return build_b_spline(t, ext_knots, ind, order, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_b_splines_actual_phe
  : public stan::model::model_base_crtp<model_b_splines_actual_phe> {
private:
        int num_data;
        int num_knots;
        vector_d knots;
        int spline_degree;
        std::vector<int> Y;
        std::vector<double> X;
        int num_basis;
        matrix_d B;
        vector_d ext_knots_temp;
        vector_d ext_knots;
public:
    model_b_splines_actual_phe(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_b_splines_actual_phe(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_b_splines_actual_phe_namespace::model_b_splines_actual_phe";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 32;
            context__.validate_dims("data initialization", "num_data", "int", context__.to_vec());
            num_data = int(0);
            vals_i__ = context__.vals_i("num_data");
            pos__ = 0;
            num_data = vals_i__[pos__++];
            current_statement_begin__ = 33;
            context__.validate_dims("data initialization", "num_knots", "int", context__.to_vec());
            num_knots = int(0);
            vals_i__ = context__.vals_i("num_knots");
            pos__ = 0;
            num_knots = vals_i__[pos__++];
            current_statement_begin__ = 34;
            validate_non_negative_index("knots", "num_knots", num_knots);
            context__.validate_dims("data initialization", "knots", "vector_d", context__.to_vec(num_knots));
            knots = Eigen::Matrix<double, Eigen::Dynamic, 1>(num_knots);
            vals_r__ = context__.vals_r("knots");
            pos__ = 0;
            size_t knots_j_1_max__ = num_knots;
            for (size_t j_1__ = 0; j_1__ < knots_j_1_max__; ++j_1__) {
                knots(j_1__) = vals_r__[pos__++];
            }
            current_statement_begin__ = 35;
            context__.validate_dims("data initialization", "spline_degree", "int", context__.to_vec());
            spline_degree = int(0);
            vals_i__ = context__.vals_i("spline_degree");
            pos__ = 0;
            spline_degree = vals_i__[pos__++];
            current_statement_begin__ = 36;
            validate_non_negative_index("Y", "num_data", num_data);
            context__.validate_dims("data initialization", "Y", "int", context__.to_vec(num_data));
            Y = std::vector<int>(num_data, int(0));
            vals_i__ = context__.vals_i("Y");
            pos__ = 0;
            size_t Y_k_0_max__ = num_data;
            for (size_t k_0__ = 0; k_0__ < Y_k_0_max__; ++k_0__) {
                Y[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 37;
            validate_non_negative_index("X", "num_data", num_data);
            context__.validate_dims("data initialization", "X", "double", context__.to_vec(num_data));
            X = std::vector<double>(num_data, double(0));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_k_0_max__ = num_data;
            for (size_t k_0__ = 0; k_0__ < X_k_0_max__; ++k_0__) {
                X[k_0__] = vals_r__[pos__++];
            }
            // initialize transformed data variables
            current_statement_begin__ = 41;
            num_basis = int(0);
            stan::math::fill(num_basis, std::numeric_limits<int>::min());
            stan::math::assign(num_basis,((num_knots + spline_degree) - 1));
            current_statement_begin__ = 42;
            validate_non_negative_index("B", "num_basis", num_basis);
            validate_non_negative_index("B", "num_data", num_data);
            B = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(num_basis, num_data);
            stan::math::fill(B, DUMMY_VAR__);
            current_statement_begin__ = 43;
            validate_non_negative_index("ext_knots_temp", "(spline_degree + num_knots)", (spline_degree + num_knots));
            ext_knots_temp = Eigen::Matrix<double, Eigen::Dynamic, 1>((spline_degree + num_knots));
            stan::math::fill(ext_knots_temp, DUMMY_VAR__);
            current_statement_begin__ = 44;
            validate_non_negative_index("ext_knots", "((2 * spline_degree) + num_knots)", ((2 * spline_degree) + num_knots));
            ext_knots = Eigen::Matrix<double, Eigen::Dynamic, 1>(((2 * spline_degree) + num_knots));
            stan::math::fill(ext_knots, DUMMY_VAR__);
            // execute transformed data statements
            current_statement_begin__ = 45;
            stan::math::assign(ext_knots_temp, append_row(rep_vector(get_base1(knots, 1, "knots", 1), spline_degree), knots));
            current_statement_begin__ = 46;
            stan::math::assign(ext_knots, append_row(ext_knots_temp, rep_vector(get_base1(knots, num_knots, "knots", 1), spline_degree)));
            current_statement_begin__ = 47;
            for (int ind = 1; ind <= num_basis; ++ind) {
                current_statement_begin__ = 48;
                stan::model::assign(B, 
                            stan::model::cons_list(stan::model::index_uni(ind), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), 
                            to_row_vector(build_b_spline(X, to_array_1d(ext_knots), ind, (spline_degree + 1), pstream__)), 
                            "assigning variable B");
            }
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 53;
            validate_non_negative_index("a_raw", "num_basis", num_basis);
            num_params_r__ += num_basis;
            current_statement_begin__ = 54;
            num_params_r__ += 1;
            current_statement_begin__ = 55;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_b_splines_actual_phe() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 53;
        if (!(context__.contains_r("a_raw")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable a_raw missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("a_raw");
        pos__ = 0U;
        validate_non_negative_index("a_raw", "num_basis", num_basis);
        context__.validate_dims("parameter initialization", "a_raw", "row_vector_d", context__.to_vec(num_basis));
        Eigen::Matrix<double, 1, Eigen::Dynamic> a_raw(num_basis);
        size_t a_raw_j_1_max__ = num_basis;
        for (size_t j_1__ = 0; j_1__ < a_raw_j_1_max__; ++j_1__) {
            a_raw(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.row_vector_unconstrain(a_raw);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable a_raw: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 54;
        if (!(context__.contains_r("tau")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable tau missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("tau");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "tau", "double", context__.to_vec());
        double tau(0);
        tau = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, tau);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable tau: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 55;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "phi", "double", context__.to_vec());
        double phi(0);
        phi = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 53;
            Eigen::Matrix<local_scalar_t__, 1, Eigen::Dynamic> a_raw;
            (void) a_raw;  // dummy to suppress unused var warning
            if (jacobian__)
                a_raw = in__.row_vector_constrain(num_basis, lp__);
            else
                a_raw = in__.row_vector_constrain(num_basis);
            current_statement_begin__ = 54;
            local_scalar_t__ tau;
            (void) tau;  // dummy to suppress unused var warning
            if (jacobian__)
                tau = in__.scalar_lb_constrain(0, lp__);
            else
                tau = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 55;
            local_scalar_t__ phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.scalar_lb_constrain(0, lp__);
            else
                phi = in__.scalar_lb_constrain(0);
            // transformed parameters
            current_statement_begin__ = 60;
            validate_non_negative_index("a", "num_basis", num_basis);
            Eigen::Matrix<local_scalar_t__, 1, Eigen::Dynamic> a(num_basis);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 61;
            validate_non_negative_index("Y_hat", "num_data", num_data);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> Y_hat(num_data);
            stan::math::initialize(Y_hat, DUMMY_VAR__);
            stan::math::fill(Y_hat, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 62;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(a_raw, 1, "a_raw", 1), 
                        "assigning variable a");
            current_statement_begin__ = 63;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(a_raw, 2, "a_raw", 1), 
                        "assigning variable a");
            current_statement_begin__ = 64;
            for (int i = 3; i <= num_basis; ++i) {
                current_statement_begin__ = 65;
                stan::model::assign(a, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (((2 * get_base1(a, (i - 1), "a", 1)) - get_base1(a, (i - 2), "a", 1)) + (get_base1(a_raw, i, "a_raw", 1) * tau)), 
                            "assigning variable a");
            }
            current_statement_begin__ = 66;
            stan::math::assign(Y_hat, to_vector(multiply(a, B)));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 60;
            size_t a_j_1_max__ = num_basis;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(a(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: a" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable a: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 61;
            size_t Y_hat_j_1_max__ = num_data;
            for (size_t j_1__ = 0; j_1__ < Y_hat_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(Y_hat(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: Y_hat" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable Y_hat: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 71;
            lp_accum__.add(normal_log<propto__>(stan::model::rvalue(a_raw, stan::model::cons_list(stan::model::index_min_max(3, num_basis), stan::model::nil_index_list()), "a_raw"), 0, 1));
            current_statement_begin__ = 72;
            lp_accum__.add(inv_gamma_log<propto__>(tau, 0.0001, 0.0001));
            current_statement_begin__ = 75;
            lp_accum__.add(neg_binomial_2_log_log<propto__>(Y, Y_hat, phi));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("a_raw");
        names__.push_back("tau");
        names__.push_back("phi");
        names__.push_back("a");
        names__.push_back("Y_hat");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(num_basis);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(num_basis);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(num_data);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_b_splines_actual_phe_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, 1, Eigen::Dynamic> a_raw = in__.row_vector_constrain(num_basis);
        size_t a_raw_j_1_max__ = num_basis;
        for (size_t j_1__ = 0; j_1__ < a_raw_j_1_max__; ++j_1__) {
            vars__.push_back(a_raw(j_1__));
        }
        double tau = in__.scalar_lb_constrain(0);
        vars__.push_back(tau);
        double phi = in__.scalar_lb_constrain(0);
        vars__.push_back(phi);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 60;
            validate_non_negative_index("a", "num_basis", num_basis);
            Eigen::Matrix<double, 1, Eigen::Dynamic> a(num_basis);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 61;
            validate_non_negative_index("Y_hat", "num_data", num_data);
            Eigen::Matrix<double, Eigen::Dynamic, 1> Y_hat(num_data);
            stan::math::initialize(Y_hat, DUMMY_VAR__);
            stan::math::fill(Y_hat, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 62;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(a_raw, 1, "a_raw", 1), 
                        "assigning variable a");
            current_statement_begin__ = 63;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(a_raw, 2, "a_raw", 1), 
                        "assigning variable a");
            current_statement_begin__ = 64;
            for (int i = 3; i <= num_basis; ++i) {
                current_statement_begin__ = 65;
                stan::model::assign(a, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (((2 * get_base1(a, (i - 1), "a", 1)) - get_base1(a, (i - 2), "a", 1)) + (get_base1(a_raw, i, "a_raw", 1) * tau)), 
                            "assigning variable a");
            }
            current_statement_begin__ = 66;
            stan::math::assign(Y_hat, to_vector(multiply(a, B)));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t a_j_1_max__ = num_basis;
                for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                    vars__.push_back(a(j_1__));
                }
                size_t Y_hat_j_1_max__ = num_data;
                for (size_t j_1__ = 0; j_1__ < Y_hat_j_1_max__; ++j_1__) {
                    vars__.push_back(Y_hat(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_b_splines_actual_phe";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t a_raw_j_1_max__ = num_basis;
        for (size_t j_1__ = 0; j_1__ < a_raw_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "a_raw" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t a_j_1_max__ = num_basis;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t Y_hat_j_1_max__ = num_data;
            for (size_t j_1__ = 0; j_1__ < Y_hat_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "Y_hat" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t a_raw_j_1_max__ = num_basis;
        for (size_t j_1__ = 0; j_1__ < a_raw_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "a_raw" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t a_j_1_max__ = num_basis;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t Y_hat_j_1_max__ = num_data;
            for (size_t j_1__ = 0; j_1__ < Y_hat_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "Y_hat" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_b_splines_actual_phe_namespace::model_b_splines_actual_phe stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
