cmake_minimum_required(VERSION 3.10)
project(DicomReader)

set(DCMTK_DIR /Data/Libs/CPP_ExtendLibs)

include_directories(${DCMTK_DIR}/include)
link_directories(${DCMTK_DIR}/lib)

add_executable(dicom_reader dicom_reader.cpp)

target_link_libraries(dicom_reader dcmdata dcmimgle ofstd)
