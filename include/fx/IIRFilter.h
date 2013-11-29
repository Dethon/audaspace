/*******************************************************************************
 * Copyright 2009-2013 Jörg Müller
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include "fx/Effect.h"

#include <vector>

AUD_NAMESPACE_BEGIN

/**
 * This sound creates a IIR filter reader.
 */
class IIRFilter : public Effect
{
private:
	/**
	 * Output filter coefficients.
	 */
	std::vector<float> m_a;

	/**
	 * Input filter coefficients.
	 */
	std::vector<float> m_b;

	// delete copy constructor and operator=
	IIRFilter(const IIRFilter&) = delete;
	IIRFilter& operator=(const IIRFilter&) = delete;

public:
	/**
	 * Creates a new IIR filter sound.
	 * \param sound The input sound.
	 * \param b The input filter coefficients.
	 * \param a The output filter coefficients.
	 */
	IIRFilter(std::shared_ptr<ISound> sound, std::vector<float> b,
						 std::vector<float> a);

	virtual std::shared_ptr<IReader> createReader();
};

AUD_NAMESPACE_END
