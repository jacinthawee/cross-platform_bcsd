
uint mem_gets(BIO *param_1,undefined *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar4 = *puVar5;
  if (param_3 <= (int)uVar4) {
    uVar4 = param_3 - 1;
  }
  if ((int)uVar4 < 1) {
    *param_2 = 0;
    return 0;
  }
  pcVar2 = (char *)puVar5[1];
  uVar3 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    if (cVar1 == '\n') {
      uVar4 = uVar3 + 1;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar4 != uVar3);
  puVar5 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar3 = *puVar5;
  if (uVar3 < uVar4) {
    if (param_2 == (undefined *)0x0) {
      if (uVar3 != 0) goto LAB_00522bb8;
    }
    else if (uVar3 != 0) goto LAB_00522b04;
    uVar3 = param_1->num;
    if (uVar3 == 0) {
      return 0;
    }
    BIO_set_flags(param_1,9);
  }
  else {
    uVar3 = uVar4;
    if (param_2 != (undefined *)0x0) {
LAB_00522b04:
      (*(code *)PTR_memcpy_006aabf4)(param_2,puVar5[1],uVar3);
      uVar4 = param_1->flags;
      *puVar5 = *puVar5 - uVar3;
      if ((uVar4 & 0x200) == 0) {
        (*(code *)PTR_memmove_006aabfc)(puVar5[1],puVar5[1] + uVar3);
        param_2 = param_2 + uVar3;
      }
      else {
        puVar5[1] = puVar5[1] + uVar3;
        param_2 = param_2 + uVar3;
      }
      goto LAB_00522b44;
    }
  }
LAB_00522bb8:
  if ((int)uVar3 < 1) {
    return uVar3;
  }
  param_2 = param_2 + uVar3;
LAB_00522b44:
  *param_2 = 0;
  return uVar3;
}

