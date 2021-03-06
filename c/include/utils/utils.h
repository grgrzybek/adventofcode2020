/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef AOC2020_UTILS_H
#define AOC2020_UTILS_H

#include <getopt.h>

namespace aoc2020 {

	class Options {
		int argc;
		char **argv;
		const char *day_name;

		bool _valid = true;
		bool _finish = false;
		int exit_code = EXIT_SUCCESS;

		std::ifstream *input_file = nullptr;

		void parse();

		void print_help();

	public:
		const char *program_name = nullptr;

		Options(const char *_day, int _argc, char *_argv[]);
		~Options();

		bool check();

		[[nodiscard]] int result() const;

		std::ifstream *file();
	};

	bool has_text(std::string &line);
	void trim(std::string &line);

}

#endif //AOC2020_UTILS_H
