/**
 * \dir
 * Contains the non-generated public header files for libqasm's new API.
 *
 * \file
 * Main include file for libqasm; this is what you should be `#include`ing.
 */

#pragma once

#include "cqasm-v1-parse-helper.hpp"
#include "cqasm-v1-analyzer.hpp"

/**
 * Toplevel namespace with entry points for the new API.
 */
namespace cqasm {

// This is the toplevel public header for the new API for v1.x. At the time it
// was written, v2 didn't exist yet, and such the v1 namespace didn't exist
// yet. Thus, to maintain API compatibility, we need to pull the v1 namespace
// into this one when this file is used.
using namespace v1;

/**
 * Parses and analyzes the given file with the default analyzer, dumping error
 * messages to stderr and throwing an analyzer::AnalysisFailed on failure.
 */
tree::One<semantic::Program> analyze(
    const std::string &filename,
    const std::string &max_version = "1.0"
);

/**
 * Parses and analyzes the given file pointer with the default analyzer, dumping
 * error messages to stderr and throwing an analyzer::AnalysisFailed on failure.
 * The optional filename is only used for error messages.
 */
tree::One<semantic::Program> analyze(
    FILE *file,
    const std::string &filename = "<unknown>",
    const std::string &max_version = "1.0"
);

/**
 * Parses and analyzes the given string with the default analyzer, dumping
 * error messages to stderr and throwing an analyzer::AnalysisFailed on failure.
 * The optional filename is only used for error messages.
 */
tree::One<semantic::Program> analyze_string(
    const std::string &data,
    const std::string &filename = "<unknown>",
    const std::string &max_version = "1.0"
);

/**
 * Constructs an Analyzer object with the defaults for cQASM 1.0 already loaded
 * into it.
 */
analyzer::Analyzer default_analyzer(
    const std::string &max_version = "1.0"
);

} // namespace cqasm
