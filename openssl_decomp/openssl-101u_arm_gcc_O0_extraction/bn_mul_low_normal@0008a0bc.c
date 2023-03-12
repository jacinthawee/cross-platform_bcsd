
void bn_mul_low_normal(ulong *param_1,ulong *param_2,ulong *param_3,uint param_4)

{
  ulong *rp;
  int num;
  uint uVar1;
  uint num_00;
  uint uVar2;
  uint num_01;
  uint uVar3;
  bool bVar4;
  
  bn_mul_words(param_1,param_2,param_4,*param_3);
  num = param_4 - 1;
  if (0 < num) {
    num_01 = param_4 - 2;
    uVar1 = num_01 & 0xfffffffc;
    uVar3 = num_01 - (param_4 & 0xfffffffc);
    uVar2 = param_4;
    while( true ) {
      bn_mul_add_words(param_1 + 1,param_2,num,param_3[1]);
      if ((int)num_01 < 1) break;
      bn_mul_add_words(param_1 + 2,param_2,num_01,param_3[2]);
      bVar4 = num_01 == uVar3;
      rp = param_1 + 3;
      param_1 = param_1 + 4;
      num_01 = num_01 - 4;
      num_00 = uVar2 - 4;
      if (bVar4) {
        return;
      }
      bn_mul_add_words(rp,param_2,uVar2 - 3,param_3[3]);
      if ((int)num_00 < 1) {
        return;
      }
      param_3 = param_3 + 4;
      bn_mul_add_words(param_1,param_2,num_00,*param_3);
      num = uVar2 - 5;
      uVar2 = num_00;
      if (num_00 == (param_4 - 4) - uVar1) {
        return;
      }
    }
  }
  return;
}

