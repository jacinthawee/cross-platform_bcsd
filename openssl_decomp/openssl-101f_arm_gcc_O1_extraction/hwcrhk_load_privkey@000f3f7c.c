
void hwcrhk_load_privkey(ENGINE *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *arg;
  int iVar1;
  RSA *r;
  BIGNUM *pBVar2;
  EVP_PKEY *pkey;
  ulong *puVar3;
  uint uVar4;
  ulong *local_44c;
  uint local_448;
  ulong *local_444;
  uint local_440;
  undefined *local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  local_43c = auStack_42c;
  local_2c = __TMC_END__;
  local_438 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x6a,"e_chil.c",0x305);
  }
  else {
    arg = (int *)CRYPTO_malloc(4,"e_chil.c",0x309);
    if (arg == (int *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(HWCRHK_lib_error_code,0x69,0x41,"e_chil.c",0x30d);
    }
    else {
      local_434 = param_3;
      local_430 = param_4;
      iVar1 = (*p_hwcrhk_RSALoadKey)(hwcrhk_context,param_2,arg,&local_43c,&local_434);
      if (iVar1 == 0) {
        if (*arg != 0) {
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,hndidx_rsa,arg);
          pBVar2 = BN_new();
          r->e = pBVar2;
          pBVar2 = BN_new();
          local_444 = pBVar2->d;
          iVar1 = r->e->dmax;
          local_440 = pBVar2->dmax << 2;
          local_44c = r->e->d;
          r->n = pBVar2;
          local_448 = iVar1 << 2;
          r->flags = r->flags | 0x20;
          iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_444,&local_44c,&local_43c);
          if (iVar1 == -3) {
            bn_expand2(r->e,local_448 >> 2);
            bn_expand2(r->n,local_440 >> 2);
            local_44c = r->e->d;
            local_448 = r->e->dmax << 2;
            local_444 = r->n->d;
            local_440 = r->n->dmax << 2;
            iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_444,&local_44c,&local_43c);
            if (iVar1 == 0) {
              pBVar2 = r->e;
              uVar4 = local_448 >> 2;
              pBVar2->top = uVar4;
              if (uVar4 != 0) {
                puVar3 = pBVar2->d + uVar4 + 0x3fffffff;
                do {
                  if (*puVar3 != 0) break;
                  uVar4 = uVar4 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar4 != 0);
                pBVar2->top = uVar4;
              }
              pBVar2 = r->n;
              uVar4 = local_440 >> 2;
              pBVar2->top = uVar4;
              if (uVar4 != 0) {
                puVar3 = pBVar2->d + uVar4 + 0x3fffffff;
                do {
                  if (*puVar3 != 0) break;
                  uVar4 = uVar4 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar4 != 0);
                pBVar2->top = uVar4;
              }
              pkey = EVP_PKEY_new();
              EVP_PKEY_assign(pkey,6,r);
              if (pkey == (EVP_PKEY *)0x0) {
                if (HWCRHK_lib_error_code == 0) {
                  HWCRHK_lib_error_code = ERR_get_next_error_library();
                }
                ERR_put_error(HWCRHK_lib_error_code,0x69,0x6e,"e_chil.c",0x348);
                pkey = (EVP_PKEY *)0x0;
              }
              goto LAB_000f4080;
            }
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = ERR_get_next_error_library();
            }
            iVar1 = 0x339;
          }
          else {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = ERR_get_next_error_library();
            }
            iVar1 = 0x32c;
          }
          ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",iVar1);
          ERR_add_error_data(1,local_43c);
          RSA_free(r);
          pkey = (EVP_PKEY *)0x0;
          goto LAB_000f4080;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x69,0x6d,"e_chil.c",0x31d);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x316);
        ERR_add_error_data(1,local_43c);
      }
    }
  }
  pkey = (EVP_PKEY *)0x0;
LAB_000f4080:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pkey);
}

