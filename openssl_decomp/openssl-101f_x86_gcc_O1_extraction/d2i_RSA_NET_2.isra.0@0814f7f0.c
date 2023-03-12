
RSA * __regparm3
d2i_RSA_NET_2_isra_0(RSA **param_1_00,uchar **param_2_00,uchar **param_3,code *param_1,int param_2)

{
  uchar *datal;
  uint uVar1;
  uint uVar2;
  EVP_MD *pEVar3;
  int iVar4;
  EVP_CIPHER *pEVar5;
  ASN1_VALUE *val;
  RSA *pRVar6;
  uint *puVar7;
  uint *puVar8;
  int in_GS_OFFSET;
  bool bVar9;
  uchar *local_1f8;
  int local_1f4;
  uchar *local_1f0;
  EVP_CIPHER_CTX local_1ec;
  uchar local_160 [64];
  uint local_120 [4];
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_108;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_CIPHER_CTX_init(&local_1ec);
  local_1f8 = (uchar *)(*param_1)(local_120,0x100,"Enter Private Key password:",0);
  puVar8 = local_120;
  if (local_1f8 != (uchar *)0x0) {
    pRVar6 = (RSA *)0x0;
    val = (ASN1_VALUE *)0x0;
    ERR_put_error(0xd,0xc9,0x67,"n_pkey.c",0x12d);
    goto LAB_0814f9e0;
  }
  do {
    puVar7 = puVar8;
    uVar1 = *puVar7 + 0xfefefeff & ~*puVar7;
    uVar2 = uVar1 & 0x80808080;
    puVar8 = puVar7 + 1;
  } while (uVar2 == 0);
  bVar9 = (uVar1 & 0x8080) == 0;
  if (bVar9) {
    uVar2 = uVar2 >> 0x10;
  }
  if (bVar9) {
    puVar8 = (uint *)((int)puVar7 + 6);
  }
  local_1f8 = (uchar *)((int)puVar8 +
                       ((-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)) - (int)local_120));
  if (param_2 == 0) {
LAB_0814f8df:
    datal = local_1f8;
    pEVar3 = EVP_md5();
    pEVar5 = EVP_rc4();
    iVar4 = EVP_BytesToKey(pEVar5,pEVar3,(uchar *)0x0,(uchar *)local_120,(int)datal,1,local_160,
                           (uchar *)0x0);
    if (iVar4 != 0) {
      OPENSSL_cleanse(local_120,0x100);
      pEVar5 = EVP_rc4();
      iVar4 = EVP_DecryptInit_ex(&local_1ec,pEVar5,(ENGINE *)0x0,local_160,(uchar *)0x0);
      if (iVar4 != 0) {
        iVar4 = EVP_DecryptUpdate(&local_1ec,*param_3,(int *)&local_1f8,*param_3,(int)*param_2_00);
        if (iVar4 != 0) {
          iVar4 = EVP_DecryptFinal_ex(&local_1ec,*param_3 + (int)local_1f8,&local_1f4);
          if (iVar4 != 0) {
            local_1f0 = *param_3;
            *param_2_00 = local_1f8 + local_1f4;
            val = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_1f0,(long)(local_1f8 + local_1f4),
                                (ASN1_ITEM *)NETSCAPE_PKEY_it);
            if (val == (ASN1_VALUE *)0x0) {
              pRVar6 = (RSA *)0x0;
              ERR_put_error(0xd,0xc9,0x9e,"n_pkey.c",0x149);
            }
            else {
              local_1f0 = (uchar *)(*(long **)(val + 8))[2];
              pRVar6 = d2i_RSAPrivateKey(param_1_00,&local_1f0,**(long **)(val + 8));
              if (pRVar6 == (RSA *)0x0) {
                ERR_put_error(0xd,0xc9,0x9d,"n_pkey.c",0x150);
              }
            }
            goto LAB_0814f9e0;
          }
        }
      }
    }
  }
  else {
    pEVar3 = EVP_md5();
    iVar4 = EVP_Digest(local_120,(size_t)local_1f8,(uchar *)local_120,(uint *)0x0,pEVar3,
                       (ENGINE *)0x0);
    if (iVar4 != 0) {
      local_110 = 0x4b434753;
      local_10c = 0x41535945;
      local_108 = 0x544c;
      local_1f8 = (uchar *)0x1a;
      goto LAB_0814f8df;
    }
  }
  pRVar6 = (RSA *)0x0;
  val = (ASN1_VALUE *)0x0;
LAB_0814f9e0:
  EVP_CIPHER_CTX_cleanup(&local_1ec);
  ASN1_item_free(val,(ASN1_ITEM *)NETSCAPE_PKEY_it);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pRVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

