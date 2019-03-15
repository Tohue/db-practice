source_filename = "test"
target datalayout = "e-m:e-p:64:64-i64:64-f80:128-n8:16:32:64-S128"

@global_var_4006f4.5 = constant [10 x i8] c"Enter x: \00"
@global_var_4006fe.6 = constant [3 x i8] c"%d\00"
@global_var_400701.7 = constant [10 x i8] c"Enter y: \00"
@global_var_40070b.8 = constant [10 x i8] c"Enter z: \00"
@global_var_400715.9 = constant [12 x i8] c"Answer: %d\0A\00"

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
  %v2_40058d = mul i64 %v0_40057a, 2454267027
  %v3_40058d = udiv i64 %v2_40058d, 4294967296
  %v3_40058f = add i64 %v3_40058d, %v0_40057a
  %v1_400592 = trunc i64 %v3_40058f to i32
  %v3_400592 = sdiv i32 %v1_400592, 4
  %v1_400599 = trunc i64 %v0_40057a to i32
  %v3_400599 = ashr i32 %v1_400599, 31
  %v4_40059e = sub nsw i32 %v3_400592, %v3_400599
  %v20_40059e = zext i32 %v4_40059e to i64
  %v1_4005a3 = add i64 %v0_400580, -5
  %v1_4005a9 = trunc i64 %v0_40057d to i32
  %v2_4005a9 = ashr i32 %v1_4005a9, 31
  %v3_4005a9 = zext i32 %v2_4005a9 to i64
  %v3_4005aa = mul nuw i64 %v3_4005a9, 4294967296
  %v4_4005aa = or i64 %v3_4005aa, %v0_40057d
  %v6_4005aa = srem i64 %v4_4005aa, %v1_4005a3
  %v7_4005b45 = and i64 %v0_40057a, 4294967295
  %v14_4005b4 = and i64 %v7_4005b45, %v0_400580
  %v6_4005bd = srem i64 %v4_4005aa, %v14_4005b4
  store i64 %v6_4005bd, i64* %rdx.global-to-local, align 8
  %v3_4005ae = sub i64 %v6_4005aa, %v6_4005bd
  %v4_4005c1 = add i64 %v3_4005ae, %v20_40059e
  %v20_4005c1 = and i64 %v4_4005c1, 4294967295
  store i64 %v20_4005c1, i64* %rsi.global-to-local, align 8
  ret i64 %v20_4005c1
}

define i64 @main(i64 %argc, i8** %argv) local_unnamed_addr {
dec_label_pc_4005c7:
  %stack_var_-20 = alloca i64, align 8
  %stack_var_-16 = alloca i64, align 8
  %stack_var_-12 = alloca i64, align 8
  %v3_4005d9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_4006f4.5, i64 0, i64 0))
  %v5_4005ef = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006fe.6, i64 0, i64 0), i64* nonnull %stack_var_-12)
  %v3_4005fe = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_400701.7, i64 0, i64 0))
  %v5_400614 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006fe.6, i64 0, i64 0), i64* nonnull %stack_var_-16)
  %v3_400623 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @global_var_40070b.8, i64 0, i64 0))
  %v5_400639 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_var_4006fe.6, i64 0, i64 0), i64* nonnull %stack_var_-20)
  %v3_40063e = load i64, i64* %stack_var_-20, align 8
  %v3_400641 = load i64, i64* %stack_var_-16, align 8
  %v3_400644 = load i64, i64* %stack_var_-12, align 8
  %v3_40064b = call i64 @f(i64 %v3_400644, i64 %v3_400641, i64 %v3_40063e)
  %v4_40065c = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_var_400715.9, i64 0, i64 0), i64 %v3_40064b)
  %v6_40065c = sext i32 %v4_40065c to i64
  ret i64 %v6_40065c
}

declare i32 @printf(i8*, ...) local_unnamed_addr

declare i32 @scanf(i8*, ...) local_unnamed_addr
