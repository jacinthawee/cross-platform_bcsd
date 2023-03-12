
undefined4
init_gen_str(BIO *param_1,EVP_PKEY_CTX **param_2,char *param_3,ENGINE *param_4,int param_5)

{
  undefined4 uVar1;
  EVP_PKEY_ASN1_METHOD *ameth;
  EVP_PKEY_CTX *ctx;
  int iVar2;
  int in_GS_OFFSET;
  ENGINE *local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (ENGINE *)0x0;
  if (*param_2 == (EVP_PKEY_CTX *)0x0) {
    ameth = EVP_PKEY_asn1_find_str(&local_28,param_3,-1);
    if ((ameth == (EVP_PKEY_ASN1_METHOD *)0x0) && (param_4 != (ENGINE *)0x0)) {
      ameth = ENGINE_get_pkey_asn1_meth_str(param_4,param_3,-1);
    }
    if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      BIO_printf(bio_err,"Algorithm %s not found\n",param_3);
      uVar1 = 0;
    }
    else {
      ERR_clear_error();
      EVP_PKEY_asn1_get0_info(&local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,ameth);
      if (local_28 != (ENGINE *)0x0) {
        ENGINE_finish(local_28);
      }
      ctx = EVP_PKEY_CTX_new_id(local_24,param_4);
      if (ctx == (EVP_PKEY_CTX *)0x0) {
        BIO_printf(param_1,"Error initializing %s context\n",param_3);
        ERR_print_errors(param_1);
        uVar1 = 0;
      }
      else {
        if (param_5 == 0) {
          iVar2 = EVP_PKEY_keygen_init(ctx);
        }
        else {
          iVar2 = EVP_PKEY_paramgen_init(ctx);
        }
        if (iVar2 < 1) {
          BIO_printf(param_1,"Error initializing %s context\n",param_3);
          ERR_print_errors(param_1);
          EVP_PKEY_CTX_free(ctx);
          uVar1 = 0;
        }
        else {
          *param_2 = ctx;
          uVar1 = 1;
        }
      }
    }
  }
  else {
    BIO_puts(param_1,"Algorithm already set!\n");
    uVar1 = 0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}

