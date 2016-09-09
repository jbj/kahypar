/***************************************************************************
 *  Copyright (C) 2014 Sebastian Schlag <sebastian.schlag@kit.edu>
 **************************************************************************/

#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace mtxconversion {
enum class MatrixFormat { COORDINATE };
enum class MatrixSymmetry { GENERAL, SYMMETRIC };

struct MatrixInfo {
  MatrixFormat format;
  MatrixSymmetry symmetry;
  int num_rows;
  int num_columns;
  int num_entries;
};

using MatrixData = std::vector<std::vector<int> >;

MatrixInfo parseHeader(std::ifstream& file);
void parseDimensionInformation(std::ifstream& file, MatrixInfo& info);
void parseMatrixEntries(std::ifstream& file, MatrixInfo& info, MatrixData& matrix_data);
void parseCoordinateMatrixEntries(std::ifstream& file, MatrixInfo& info, MatrixData& matrix_data);
void writeMatrixInHgrFormat(const MatrixInfo& info, const MatrixData& matrix_data, const std::string& filename);
void convertMtxToHgr(const std::string& matrix_filename, const std::string& hypergraph_filename);
}  // namespace mtxconversion