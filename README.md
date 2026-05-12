# Movie Recommender

C++ 기반 영화 추천 시스템 — 숭실대학교 C++ 프로그래밍

## 프로젝트 구조

movie-recommender/
├── src/
│   ├── main.cpp
│   ├── Movie.h / MovieManager.h / MovieManager.cpp
│   ├── User.h / UserManager.h / UserManager.cpp
│   ├── Rating.h / RatingManager.h / RatingManager.cpp
│   ├── SimilarityCalculator.h / SimilarityCalculator.cpp
│   ├── Recommender.h / Recommender.cpp
│   └── Makefile
├── data/
│   ├── movies.csv
│   ├── users.csv
│   └── ratings.csv
└── README.md

## 빌드 및 실행

cd src
make
make run

## 유사도 공식

similarity = (공통 영화 수 × 10) - (평점 차이의 합)
값이 클수록 더 비슷한 취향

## 추천 흐름

1. 모든 사용자와 유사도 계산
2. 유사도 상위 K명 선택
3. K명이 높게 평가한 영화 중 내가 안 본 영화 수집
4. 점수 내림차순 정렬 후 상위 N개 추천

## 엣지 케이스 처리

- 공통 영화 0개 → 유사도 -100 반환
- 평점 데이터 없는 유저 → "평점 데이터가 없습니다" 출력
- 추천할 영화 없음 → "추천할 영화가 없습니다" 출력
- 유사 사용자 K명 미만 → 있는 만큼만 반환
- 추천 영화 N개 미만 → 있는 만큼만 반환