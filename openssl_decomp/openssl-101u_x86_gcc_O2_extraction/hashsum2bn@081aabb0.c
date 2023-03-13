
BIGNUM * hashsum2bn(uchar *param_1)

{
  uchar uVar1;
  uchar *puVar2;
  int len;
  BIGNUM *a;
  uchar *puVar3;
  int in_GS_OFFSET;
  uchar local_31;
  uchar local_30 [32];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  puVar3 = local_30 + 0x1f;
  do {
    uVar1 = *param_1;
    puVar2 = puVar3 + -1;
    param_1 = param_1 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar2;
  } while (puVar2 != &local_31);
  len = 0x20;
  puVar3 = local_30;
  if (local_30[0] == '\0') {
    do {
      puVar3 = puVar3 + 1;
      len = len + -1;
      if (*puVar3 != '\0') {
        if (len != 0) goto LAB_081aac0b;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
  }
  else {
LAB_081aac0b:
    a = BN_bin2bn(puVar3,len,(BIGNUM *)0x0);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

