
undefined4 eckey_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  undefined4 uVar2;
  EC_KEY *pEVar3;
  int in_GS_OFFSET;
  uchar *local_28;
  void *local_24;
  int local_20;
  long local_1c;
  EC_KEY *local_18;
  X509_ALGOR *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (uchar *)0x0;
  local_18 = (EC_KEY *)0x0;
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_28,&local_1c,&local_14,param_2);
  if (iVar1 != 0) {
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_20,&local_24,local_14);
    local_18 = (EC_KEY *)eckey_type2param();
    if (local_18 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0xd7,0x10,"ec_ameth.c",0xc3);
      uVar2 = 0;
      goto LAB_081bcae8;
    }
    pEVar3 = o2i_ECPublicKey(&local_18,&local_28,local_1c);
    if (pEVar3 != (EC_KEY *)0x0) {
      EVP_PKEY_assign(param_1,0x198,local_18);
      uVar2 = 1;
      goto LAB_081bcae8;
    }
    ERR_put_error(0x10,0xd7,0x8e,"ec_ameth.c",0xc9);
    if (local_18 != (EC_KEY *)0x0) {
      EC_KEY_free(local_18);
    }
  }
  uVar2 = 0;
LAB_081bcae8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

