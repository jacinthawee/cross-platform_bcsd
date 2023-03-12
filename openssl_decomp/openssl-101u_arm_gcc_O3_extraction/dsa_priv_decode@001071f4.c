
undefined4 dsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  _STACK *ai;
  int *piVar2;
  int *piVar3;
  DSA *r;
  undefined4 uVar4;
  _STACK *st;
  BIGNUM *ctx;
  uchar *local_30;
  long local_2c;
  int local_28;
  long *local_24;
  X509_ALGOR *local_20;
  uchar *local_1c;
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_30,&local_2c,&local_20,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_28,&local_24,local_20);
  if (*local_30 == '0') {
    st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_30,local_2c);
    ai = st;
    if (st != (_STACK *)0x0) {
      iVar1 = sk_num(st);
      if (iVar1 == 2) {
        piVar2 = (int *)sk_value(st,0);
        piVar3 = (int *)sk_value(st,1);
        if (*piVar2 == 0x10) {
          param_2->broken = 2;
          local_24 = (long *)piVar2[1];
        }
        else {
          if (local_28 != 0x10) goto LAB_0010734c;
          param_2->broken = 3;
        }
        if (*piVar3 == 2) {
          ai = (_STACK *)piVar3[1];
          goto LAB_001072c6;
        }
      }
LAB_0010734c:
      ai = (_STACK *)0x0;
    }
LAB_00107254:
    r = (DSA *)0x0;
    ERR_put_error(10,0x73,0x72,"dsa_ameth.c",0x110);
    ctx = (BIGNUM *)0x0;
  }
  else {
    local_1c = local_30;
    ai = (_STACK *)d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_30,local_2c);
    if (ai == (_STACK *)0x0) {
LAB_00107374:
      ai = (_STACK *)0x0;
LAB_00107252:
      st = (_STACK *)0x0;
      goto LAB_00107254;
    }
    if (ai->data == (char **)0x102) {
      param_2->broken = 4;
      ASN1_STRING_clear_free();
      ai = (_STACK *)d2i_ASN1_UINTEGER((ASN1_INTEGER **)0x0,&local_1c,local_2c);
      if (ai == (_STACK *)0x0) goto LAB_00107374;
    }
    if (local_28 != 0x10) goto LAB_00107252;
    st = (_STACK *)0x0;
LAB_001072c6:
    local_1c = (uchar *)local_24[2];
    r = d2i_DSAparams((DSA **)0x0,&local_1c,*local_24);
    if (r == (DSA *)0x0) goto LAB_00107254;
    ctx = ASN1_INTEGER_to_BN((ASN1_INTEGER *)ai,(BIGNUM *)0x0);
    iVar1 = 0xf8;
    r->priv_key = ctx;
    if (ctx == (BIGNUM *)0x0) {
LAB_00107328:
      ERR_put_error(10,0x73,0x6d,"dsa_ameth.c",iVar1);
    }
    else {
      ctx = BN_new();
      iVar1 = 0xfd;
      r->pub_key = ctx;
      if (ctx != (BIGNUM *)0x0) {
        ctx = (BIGNUM *)BN_CTX_new();
        if (ctx != (BIGNUM *)0x0) {
          iVar1 = BN_mod_exp(r->pub_key,r->g,r->priv_key,r->p,(BN_CTX *)ctx);
          if (iVar1 != 0) {
            uVar4 = 1;
            EVP_PKEY_assign(param_1,0x74,r);
            goto LAB_00107278;
          }
          iVar1 = 0x106;
          goto LAB_00107328;
        }
        iVar1 = 0x101;
      }
      ERR_put_error(10,0x73,0x41,"dsa_ameth.c",iVar1);
    }
  }
  uVar4 = 0;
  DSA_free(r);
LAB_00107278:
  BN_CTX_free((BN_CTX *)ctx);
  if (st == (_STACK *)0x0) {
    ASN1_STRING_clear_free(ai);
    return uVar4;
  }
  sk_pop_free(st,ASN1_TYPE_free + 1);
  return uVar4;
}

