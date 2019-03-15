source_filename = "test"
target datalayout = "e-m:e-p:64:64-i64:64-f80:128-n8:16:32:64-S128"

@global_var_4006e4.5 = constant [10 x i8] c"Enter x: \00"
@global_var_4006ee.6 = constant [3 x i8] c"%d\00"
@global_var_4006f1.7 = constant [10 x i8] c"Enter y: \00"
@global_var_4006fb.8 = constant [10 x i8] c"Enter z: \00"
@global_var_400705.9 = constant [12 x i8] c"Answer: %d\0A\00"

define i64 @f(i64 %arg1, i64 %arg2, i64 %arg3) local_unnamed_addr {
dec_label_pc_400576:
  %rdi.global-to-local = alloca i64, align 8
  %rdx.global-to-local = alloca i64, align 8
  %rsi.global-to-local = alloca i64, align 8
  store i64 %arg3, i64* %rdx.global-to-local, align 8
  store i64 %arg2, i64* %rsi.global-to-local, align 8
  store i64 %arg1, i64* %rdi.global-to-local, align 8
  %v0_40057a = load i64, i64* %rdi.global-to-local, align 8
  %v0_40057d = load i64, i64* %rsi.global-to-local, align 8
  %v0_400580 = load i64, i64* %rdx.global-to-local, align 8
  %v2_40058d = mul i64 %v0_40057a, 1431655766
  %v3_40058d = udiv i64 %v2_40058d, 4294967296
  %v1_400591 = trunc i64 %v0_40057a to i32
  %v3_400591 = ashr i32 %v1_400591, 31
  %v1_400594 = trunc i64 %v3_40058d to i32
  %v4_400594 = sub i32 %v1_400594, %v3_400591
  %tmp12 = mul i32 %v4_400594, -3
  %v4_40059c = add i32 %tmp12, %v1_400591
  %v20_40059c = zext i32 %v4_40059c to i64
  %v3_4005a3 = add i64 %v20_40059c, %v0_400580
  store i64 %v0_40057d, i64* %rdx.global-to-local, align 8
  %v4_4005ac = add i64 %v0_40057d, %v0_40057a
  %v7_4005ae = and i64 %v4_4005ac, %v0_40057d
  %v4_4005b1 = or i64 %v3_4005a3, %v7_4005ae
  %v11_4005b1 = and i64 %v4_4005b1, 4294967295
  ret i64 %v11_4005b1
}

define i64 @main(i64 %argc, i8** %argv) local_unnamed_addr {
dec_label_pc_4005b5:
  %stack_var_-20 = alloca i64, align 8
  %stack_var_-16 = alloca i64, align 8
  %stack_var_-12 = alloca i64, align 8
  %v3_4005c7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_4006e4.5, i64 0, i64 0))
  %v5_4005dd = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006ee.6, i64 0, i64 0), i64* nonnull %stack_var_-12)
  %v3_4005ec = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_4006f1.7, i64 0, i64 0))
  %v5_400602 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006ee.6, i64 0, i64 0), i64* nonnull %stack_var_-16)
  %v3_400611 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_4006fb.8, i64 0, i64 0))
  %v5_400627 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006ee.6, i64 0, i64 0), i64* nonnull %stack_var_-20)
  %v3_40062c = load i64, i64* %stack_var_-20, align 8
  %v3_40062f = load i64, i64* %stack_var_-16, align 8
  %v3_400632 = load i64, i64* %stack_var_-12, align 8
  %v3_400639 = call i64 @f(i64 %v3_400632, i64 %v3_40062f, i64 %v3_40062c)
  %v4_40064a = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_var_400705.9, i64 0, i64 0), i64 %v3_400639)
  %v6_40064a = sext i32 %v4_40064a to i64
  ret i64 %v6_40064a
}

declare i32 @printf(i8*, ...) local_unnamed_addr

declare i32 @scanf(i8*, ...) local_unnamed_addr
