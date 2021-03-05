#==============================
# Requirements
#==============================

cmake_minimum_required(VERSION 3.10)

#==============================
# Project Settings
#==============================

project("Gaia Connections" LANGUAGES CXX)

#==============================
# Inner Units
#==============================

# UDP Connection Library
add_subdirectory("PacketConnection")

#==============================
# Outer Units
#==============================