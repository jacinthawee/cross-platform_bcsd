
undefined4 cca_get_random_bytes(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  int local_44;
  undefined local_40 [4];
  undefined local_3c [7];
  undefined local_35 [4];
  undefined4 local_31 [4];
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_31[2] = 0x444e4152;
  local_31[3] = 0x20204d4f;
  local_21 = 0;
  if (7 < (int)param_2) {
    puVar3 = param_1;
    do {
      (*randomNumberGenerate)(&local_44,local_40,local_3c,local_35,local_31 + 2,local_31);
      if (local_44 != 0) goto LAB_0819c5e3;
      param_2 = param_2 - 8;
      param_1 = puVar3 + 2;
      *puVar3 = local_31[0];
      puVar3[1] = local_31[1];
      puVar3 = param_1;
    } while (7 < param_2);
  }
  uVar1 = 1;
  if (param_2 != 0) {
    (*randomNumberGenerate)(&local_44,local_40,0,0,local_31 + 2,local_31);
    if (local_44 == 0) {
      uVar2 = 0;
      do {
        *(undefined *)((int)param_1 + uVar2) = *(undefined *)((int)local_31 + uVar2);
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2);
      uVar1 = 1;
    }
    else {
LAB_0819c5e3:
      uVar1 = 0;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

