@echo off

build ray_tracer optimized 1_lane && ray_tracer.exe test_1_lane.bmp && test_1_lane.bmp
build ray_tracer optimized 4_lanes && ray_tracer.exe test_4_lanes.bmp && test_4_lanes.bmp