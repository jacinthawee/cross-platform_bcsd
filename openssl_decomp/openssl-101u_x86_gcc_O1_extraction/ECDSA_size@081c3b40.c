
int ECDSA_size(EC_KEY *eckey)

{
  EC_GROUP *group;
  BIGNUM *order;
  int iVar1;
  int in_GS_OFFSET;
  ASN1_INTEGER local_24;
  uchar local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (eckey != (EC_KEY *)0x0) {
    group = EC_KEY_get0_group(eckey);
    if (group != (EC_GROUP *)0x0) {
      order = BN_new();
      if (order != (BIGNUM *)0x0) {
        iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
        if (iVar1 == 0) {
          BN_clear_free(order);
        }
        else {
          iVar1 = BN_num_bits(order);
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
          BN_clear_free(order);
        }
        goto LAB_081c3bfa;
      }
    }
  }
  iVar1 = 0;
LAB_081c3bfa:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

