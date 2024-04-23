# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/esp4.4/frameworks/esp-idf-v4.4.6/components/bootloader/subproject"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix/tmp"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix/src"
  "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/thomas.dacosta/esp4.4/v4.4.6/esp-idf/examples/personal_project/T-H-P_Room_Sensor/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()