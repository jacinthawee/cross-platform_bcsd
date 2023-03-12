
int DSA_size(DSA *param_1)

{
  int iVar1;
  ASN1_INTEGER local_28;
  uchar local_18 [4];
  int local_14;
  
  local_28.data = local_18;
  local_14 = __TMC_END__;
  iVar1 = BN_num_bits(param_1->q);
  local_28.length = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    local_28.length = iVar1 + 0xe;
  }
  local_28.length = local_28.length >> 3;
  local_28.type = 2;
  local_18[0] = 0xff;
  iVar1 = i2d_ASN1_INTEGER(&local_28,(uchar **)0x0);
  iVar1 = ASN1_object_size(1,iVar1 << 1,0x10);
  if (local_14 == __TMC_END__) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

