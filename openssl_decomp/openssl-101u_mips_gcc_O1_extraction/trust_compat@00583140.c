
undefined4 trust_compat(undefined4 param_1,X509 *param_2)

{
  undefined4 uVar1;
  
  X509_check_purpose(param_2,-1,0);
  uVar1 = 3;
  if ((param_2->ex_flags & 0x20) != 0) {
    uVar1 = 1;
  }
  return uVar1;
}

