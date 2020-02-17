cmake_minimum_required(VERSION 3.13)
project(HW8)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        HW8 main.cpp InterfacePrint.h Employee.cpp Employee.h CEO.cpp CEO.h Director.cpp
        Director.h Secretary.cpp Secretary.h Office.cpp Office.h Department.cpp Department.h
        Event.h Event.cpp FundsBalance.cpp FundsBalance.h Budget.cpp Budget.h
        AbstractEventOrCause.h Cause.h Cause.cpp Trust.cpp Trust.h GrandDepartment.cpp
        GrandDepartment.h FundRaisingDepartment.cpp FundRaisingDepartment.h)