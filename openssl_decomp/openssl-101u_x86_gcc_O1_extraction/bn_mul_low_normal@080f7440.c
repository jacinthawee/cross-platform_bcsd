
void bn_mul_low_normal(ulong *param_1,ulong *param_2,ulong *param_3,uint param_4)

{
  int num;
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint num_00;
  
  bn_mul_words(param_1,param_2,param_4,*param_3);
  num_00 = param_4 - 1;
  if (0 < (int)num_00) {
    uVar4 = num_00 - (param_4 + 1 & 0xfffffffc);
    uVar2 = num_00 & 3;
    uVar3 = num_00 - (param_4 & 0xfffffffc);
    do {
      bn_mul_add_words(param_1 + 1,param_2,num_00,param_3[1]);
      if (uVar4 == num_00) {
        return;
      }
      bn_mul_add_words(param_1 + 2,param_2,num_00 - 1,param_3[2]);
      if (num_00 == uVar3) {
        return;
      }
      bn_mul_add_words(param_1 + 3,param_2,num_00 - 2,param_3[3]);
      num = num_00 - 3;
      if (num_00 == uVar2) {
        return;
      }
      param_1 = param_1 + 4;
      puVar1 = param_3 + 4;
      num_00 = num_00 - 4;
      param_3 = param_3 + 4;
      bn_mul_add_words(param_1,param_2,num,*puVar1);
    } while (0 < (int)num_00);
  }
  return;
}

