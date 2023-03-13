
int DSA_size(DSA *param_1)

{
  int iVar1;
  int in_GS_OFFSET;
  ASN1_INTEGER local_24;
  uchar local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BN_num_bits(param_1->q);
  local_24.type = 2;
  local_14[0] = 0xff;
  local_24.length = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    local_24.length = iVar1 + 0xe;
  }
  local_24.length = local_24.length >> 3;
  local_24.data = local_14;
  iVar1 = i2d_ASN1_INTEGER(&local_24,(uchar **)0x0);
  iVar1 = ASN1_object_size(1,iVar1 * 2,0x10);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

