
void bn_mul_low_normal(ulong *param_1,ulong *param_2,ulong *param_3,int param_4)

{
  ulong *puVar1;
  int num;
  int num_00;
  int num_01;
  
  num = param_4 + -1;
  bn_mul_words(param_1,param_2,param_4,*param_3);
  if (0 < num) {
    num_00 = param_4 + -2;
    num_01 = param_4 + -3;
    do {
      param_4 = param_4 + -4;
      bn_mul_add_words(param_1 + 1,param_2,num,param_3[1]);
      num = num + -4;
      if (num_00 < 1) {
        return;
      }
      bn_mul_add_words(param_1 + 2,param_2,num_00,param_3[2]);
      puVar1 = param_1 + 3;
      param_1 = param_1 + 4;
      if (num_01 < 1) {
        return;
      }
      bn_mul_add_words(puVar1,param_2,num_01,param_3[3]);
      if (param_4 < 1) {
        return;
      }
      puVar1 = param_3 + 4;
      param_3 = param_3 + 4;
      bn_mul_add_words(param_1,param_2,param_4,*puVar1);
      num_00 = num_00 + -4;
      num_01 = num_01 + -4;
    } while (0 < num);
  }
  return;
}

