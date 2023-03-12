
int ECDSA_size(EC_KEY *eckey)

{
  EC_GROUP *group;
  BIGNUM *order;
  int iVar1;
  ASN1_INTEGER local_28;
  uchar local_18 [4];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (((eckey == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(eckey), group == (EC_GROUP *)0x0)) ||
     (order = BN_new(), order == (BIGNUM *)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
    if (iVar1 != 0) {
      iVar1 = BN_num_bits(order);
      local_28.data = local_18;
      local_28.type = 2;
      local_28.length = iVar1 + 0xe;
      if (-1 < iVar1 + 7) {
        local_28.length = iVar1 + 7;
      }
      local_28.length = local_28.length >> 3;
      local_18[0] = 0xff;
      iVar1 = i2d_ASN1_INTEGER(&local_28,(uchar **)0x0);
      iVar1 = ASN1_object_size(1,iVar1 << 1,0x10);
    }
    BN_clear_free(order);
  }
  if (local_14 == __stack_chk_guard) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

