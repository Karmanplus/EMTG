// EMTG: Evolutionary Mission Trajectory Generator
// An open-source global optimization tool for preliminary mission design
// Provided by NASA Goddard Space Flight Center
//
// Copyright (c) 2013 - 2020 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration.
// All Other Rights Reserved.

// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.

// Licensed under the NASA Open Source License (the "License"); 
// You may not use this file except in compliance with the License. 
// You may obtain a copy of the License at:
// https://opensource.org/licenses/NASA-1.3
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
// express or implied.   See the License for the specific language
// governing permissions and limitations under the License.

#include "sparsey_thing.h"

namespace EMTG
{
    void sparsey_thing::setup_calcbounds(
        std::vector<double>* Xupperbounds,
        std::vector<double>* Xlowerbounds,
        std::vector<double>* X_scale_factors,
        std::vector<double>* Fupperbounds,
        std::vector<double>* Flowerbounds,
		std::vector<double>* F_scale_factors,
        std::vector<std::string>* Xdescriptions,
        std::vector<std::string>* Fdescriptions,
        std::vector<size_t>* iGfun,
        std::vector<size_t>* jGvar,
        std::vector<std::string>* Gdescriptions,
        std::vector<size_t>* iAfun,
        std::vector<size_t>* jAvar,
        std::vector<std::string>* Adescriptions,
        std::vector<double>* A)
    {
        this->Xupperbounds = Xupperbounds;
        this->Xlowerbounds = Xlowerbounds;
        this->X_scale_factors = X_scale_factors;
        this->Xdescriptions = Xdescriptions;
        this->Fupperbounds = Fupperbounds;
        this->Flowerbounds = Flowerbounds;
        this->Fdescriptions = Fdescriptions;
        this->iGfun = iGfun;
        this->jGvar = jGvar;
        this->Gdescriptions = Gdescriptions;
        this->iAfun = iAfun;
        this->jAvar = jAvar;
        this->Adescriptions = Adescriptions;
        this->A = A;
    }

    //******************************************sparsity pattern stuff
    //we keep these in phase so that we can have a shorter call interface
    size_t
        sparsey_thing::create_sparsity_entry(const size_t& Findex,
            const size_t& Xstart,
            const bool& ForwardPass,
            const std::string& variable_name,
            size_t& sparsity_index_container)
    {
        return solver_utilities::create_sparsity_entry(Findex,
            Xstart,
            ForwardPass,
            variable_name,
            *Fdescriptions,
            *Xdescriptions,
            *Gdescriptions,
            *iGfun,
            *jGvar,
            sparsity_index_container);
    }

    size_t
        sparsey_thing::create_sparsity_entry(const size_t& Findex,
            const size_t& Xstart,
            const bool& ForwardPass,
            const std::string& variable_name,
            std::vector<size_t>& sparsity_index_container)
    {
        return solver_utilities::create_sparsity_entry(Findex,
            Xstart,
            ForwardPass,
            variable_name,
            *Fdescriptions,
            *Xdescriptions,
            *Gdescriptions,
            *iGfun,
            *jGvar,
            sparsity_index_container);
    }

    size_t
        sparsey_thing::create_sparsity_entry(const size_t& Findex,
            const size_t& Xindex,
            size_t& sparsity_index_container)
    {
        return solver_utilities::create_sparsity_entry(Findex,
            Xindex,
            *Fdescriptions,
            *Xdescriptions,
            *Gdescriptions,
            *iGfun,
            *jGvar,
            sparsity_index_container);
    }

    size_t
        sparsey_thing::create_sparsity_entry(const size_t& Findex,
            const size_t& Xindex,
            std::vector<size_t>& sparsity_index_container)
    {
        return solver_utilities::create_sparsity_entry(Findex,
            Xindex,
            *Fdescriptions,
            *Xdescriptions,
            *Gdescriptions,
            *iGfun,
            *jGvar,
            sparsity_index_container);
    }

    void
        sparsey_thing::create_sparsity_entry_vector(const size_t& Findex,
            const size_t& Xstart,
            const bool& ForwardPass,
            const int& number_of_entries,
            const std::string& variable_name,
            std::vector<size_t>& sparsity_index_container)
    {
        solver_utilities::create_sparsity_entry_vector(Findex,
            Xstart,
            ForwardPass,
            number_of_entries,
            variable_name,
            *Fdescriptions,
            *Xdescriptions,
            *Gdescriptions,
            *iGfun,
            *jGvar,
            sparsity_index_container);
    }
}