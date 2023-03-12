
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void d2i_RSA_NET_2_isra_0(RSA **param_1,int *param_2,_func_1619 **param_3,code *param_4,int param_5)

{
  size_t count;
  EVP_CIPHER *pEVar1;
  EVP_MD *pEVar2;
  int iVar3;
  RSA *val;
  RSA *pRVar4;
  size_t local_1fc;
  int local_1f8;
  _func_1619 *local_1f4;
  uchar auStack_1f0 [64];
  EVP_CIPHER_CTX EStack_1b0;
  uchar auStack_124 [16];
  undefined4 local_114;
  undefined4 uStack_110;
  undefined2 local_10c;
  int local_24;
  
  local_24 = __TMC_END__;
  EVP_CIPHER_CTX_init(&EStack_1b0);
  local_1fc = (*param_4)(auStack_124,0x100,"Enter Private Key password:",0);
  if (local_1fc != 0) {
    pRVar4 = (RSA *)0x0;
    ERR_put_error(0xd,0xc9,0x67,"n_pkey.c",0x12d);
    val = (RSA *)0x0;
    goto LAB_000c00ec;
  }
  count = strlen((char *)auStack_124);
  local_1fc = count;
  if (param_5 == 0) {
LAB_000c0020:
    pEVar1 = EVP_rc4();
    pEVar2 = EVP_md5();
    iVar3 = EVP_BytesToKey(pEVar1,pEVar2,(uchar *)0x0,auStack_124,local_1fc,1,auStack_1f0,
                           (uchar *)0x0);
    if (iVar3 != 0) {
      OPENSSL_cleanse(auStack_124,0x100);
      pEVar1 = EVP_rc4();
      iVar3 = EVP_DecryptInit_ex(&EStack_1b0,pEVar1,(ENGINE *)0x0,auStack_1f0,(uchar *)0x0);
      if (iVar3 != 0) {
        iVar3 = EVP_DecryptUpdate(&EStack_1b0,(uchar *)*param_3,(int *)&local_1fc,(uchar *)*param_3,
                                  *param_2);
        if ((iVar3 != 0) &&
           (iVar3 = EVP_DecryptFinal_ex(&EStack_1b0,(uchar *)(*param_3 + local_1fc),&local_1f8),
           iVar3 != 0)) {
          local_1f4 = *param_3;
          *param_2 = local_1f8 + local_1fc;
          val = (RSA *)ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)&local_1f4,local_1f8 + local_1fc,
                                     (ASN1_ITEM *)&NETSCAPE_PKEY_it);
          if (val == (RSA *)0x0) {
            ERR_put_error(0xd,0xc9,0x9e,"n_pkey.c",0x149);
            pRVar4 = val;
          }
          else {
            local_1f4 = val->meth->rsa_pub_dec;
            pRVar4 = d2i_RSAPrivateKey(param_1,(uchar **)&local_1f4,(long)val->meth->name);
            if (pRVar4 == (RSA *)0x0) {
              ERR_put_error(0xd,0xc9,0x9d,"n_pkey.c",0x150);
            }
          }
          goto LAB_000c00ec;
        }
      }
    }
  }
  else {
    pEVar2 = EVP_md5();
    iVar3 = EVP_Digest(auStack_124,count,auStack_124,(uint *)0x0,pEVar2,(ENGINE *)0x0);
    if (iVar3 != 0) {
      local_114 = s_SGCKEYSALT_00163860._0_4_;
      uStack_110 = s_SGCKEYSALT_00163860._4_4_;
      local_1fc = 0x1a;
      local_10c = (undefined2)ram0x00163868;
      goto LAB_000c0020;
    }
  }
  pRVar4 = (RSA *)0x0;
  val = (RSA *)0x0;
LAB_000c00ec:
  EVP_CIPHER_CTX_cleanup(&EStack_1b0);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&NETSCAPE_PKEY_it);
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pRVar4);
}

