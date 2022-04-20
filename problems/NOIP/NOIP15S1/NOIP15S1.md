# 题目描述

幻方是一种很神奇的 $N*N$ 矩阵：它由数字 $1,2,3,\cdots,N \times N$ 构成，且每行、每列及两条对角线上的数字之和都相同。

当 $N$ 为奇数时，我们可以通过下方法构建一个幻方：

首先将 $1$ 写在第一行的中间。

之后，按如下方式从小到大依次填写每个数 $K (K=2,3,\cdots,N \times N)$：

1. 若 $(K-1)$ 在第一行但不在最后一列，则将 $K$ 填在最后一行，$(K-1)$ 所在列的右一列；
2. 若 $(K-1)$ 在最后一列但不在第一行，则将 $K$ 填在第一列，$(K-1)$ 所在行的上一行；
3. 若 $(K-1)$ 在第一行最后一列，则将 $K$ 填在 $(K-1)$ 的正下方；
4. 若 $(K-1)$ 既不在第一行，也不在最后一列，如果 $(K-1)$ 的右上方还未填数，则将 $K$ 填在 $(K-1)$ 的右上方，否则将 $K$ 填在 $(K-1)$ 的正下方。

现给定 $N$，请按上述方法构造 $N \times N$ 的幻方。

# 输入格式

一个正整数 $N$，即幻方的大小。

# 输出格式

共 $N$ 行，每行 $N$ 个整数，即按上述方法构造出的 $N \times N$ 的幻方，相邻两个整数之间用单空格隔开。

# 输入输出样例

```input1
3
```

```output1
8 1 6
3 5 7
4 9 2
```

```input2
25
```

```output2
327 354 381 408 435 462 489 516 543 570 597 624 1 28 55 82 109 136 163 190 217 244 271 298 325
353 380 407 434 461 488 515 542 569 596 623 25 27 54 81 108 135 162 189 216 243 270 297 324 326
379 406 433 460 487 514 541 568 595 622 24 26 53 80 107 134 161 188 215 242 269 296 323 350 352
405 432 459 486 513 540 567 594 621 23 50 52 79 106 133 160 187 214 241 268 295 322 349 351 378
431 458 485 512 539 566 593 620 22 49 51 78 105 132 159 186 213 240 267 294 321 348 375 377 404
457 484 511 538 565 592 619 21 48 75 77 104 131 158 185 212 239 266 293 320 347 374 376 403 430
483 510 537 564 591 618 20 47 74 76 103 130 157 184 211 238 265 292 319 346 373 400 402 429 456
509 536 563 590 617 19 46 73 100 102 129 156 183 210 237 264 291 318 345 372 399 401 428 455 482
535 562 589 616 18 45 72 99 101 128 155 182 209 236 263 290 317 344 371 398 425 427 454 481 508
561 588 615 17 44 71 98 125 127 154 181 208 235 262 289 316 343 370 397 424 426 453 480 507 534
587 614 16 43 70 97 124 126 153 180 207 234 261 288 315 342 369 396 423 450 452 479 506 533 560
613 15 42 69 96 123 150 152 179 206 233 260 287 314 341 368 395 422 449 451 478 505 532 559 586
14 41 68 95 122 149 151 178 205 232 259 286 313 340 367 394 421 448 475 477 504 531 558 585 612
40 67 94 121 148 175 177 204 231 258 285 312 339 366 393 420 447 474 476 503 530 557 584 611 13
66 93 120 147 174 176 203 230 257 284 311 338 365 392 419 446 473 500 502 529 556 583 610 12 39
92 119 146 173 200 202 229 256 283 310 337 364 391 418 445 472 499 501 528 555 582 609 11 38 65
118 145 172 199 201 228 255 282 309 336 363 390 417 444 471 498 525 527 554 581 608 10 37 64 91
144 171 198 225 227 254 281 308 335 362 389 416 443 470 497 524 526 553 580 607 9 36 63 90 117
170 197 224 226 253 280 307 334 361 388 415 442 469 496 523 550 552 579 606 8 35 62 89 116 143
196 223 250 252 279 306 333 360 387 414 441 468 495 522 549 551 578 605 7 34 61 88 115 142 169
222 249 251 278 305 332 359 386 413 440 467 494 521 548 575 577 604 6 33 60 87 114 141 168 195
248 275 277 304 331 358 385 412 439 466 493 520 547 574 576 603 5 32 59 86 113 140 167 194 221
274 276 303 330 357 384 411 438 465 492 519 546 573 600 602 4 31 58 85 112 139 166 193 220 247
300 302 329 356 383 410 437 464 491 518 545 572 599 601 3 30 57 84 111 138 165 192 219 246 273
301 328 355 382 409 436 463 490 517 544 571 598 625 2 29 56 83 110 137 164 191 218 245 272 299
```

# 说明/提示

对于 $100 \%$ 的数据，$1 \leq N \leq 39$ 且 $N$ 为奇数。