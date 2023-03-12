
void hashsum2bn(int param_1)

{
  undefined *puVar1;
  BIGNUM *a;
  int len;
  uchar *s;
  undefined *puVar2;
  uchar local_38 [32];
  undefined auStack_18 [4];
  int local_14;
  
  s = local_38;
  puVar1 = (undefined *)(param_1 + -1);
  puVar2 = auStack_18;
  local_14 = __TMC_END__;
  do {
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + -1;
    *puVar2 = *puVar1;
  } while (puVar2 != local_38);
  if (local_38[0] == '\0') {
    len = 0x20;
    s = local_38;
    do {
      s = s + 1;
      len = len + -1;
      if (*s != '\0') {
        if (len != 0) goto LAB_000f9318;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
  }
  else {
    len = 0x20;
LAB_000f9318:
    a = BN_bin2bn(s,len,(BIGNUM *)0x0);
  }
  if (local_14 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(a);
}

