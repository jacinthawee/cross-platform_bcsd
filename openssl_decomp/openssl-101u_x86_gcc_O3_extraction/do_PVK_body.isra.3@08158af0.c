
undefined4 __regparm3
do_PVK_body_isra_3(EVP_MD *param_1_00,size_t param_2_00,uint param_3,code *param_1,void *param_2)

{
  _func_1078 **pp_Var1;
  uint uVar2;
  ulong uVar3;
  EVP_MD *type;
  int iVar4;
  int *out;
  EVP_CIPHER *pEVar5;
  bool bVar6;
  undefined4 uVar7;
  int *piVar8;
  int in_GS_OFFSET;
  int line;
  EVP_MD *local_4e8;
  size_t local_4e4;
  char *local_4e0;
  EVP_MD_CTX local_4d8;
  EVP_CIPHER_CTX local_4c0;
  uchar local_434 [5];
  undefined4 local_42f;
  undefined4 local_42b;
  undefined2 local_427;
  undefined local_425;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_CIPHER_CTX_init(&local_4c0);
  if (param_2_00 == 0) {
    bVar6 = false;
    local_4e8 = (EVP_MD *)0x0;
    local_4d8.digest = param_1_00;
    if (param_3 < 0x10) goto LAB_08158de0;
LAB_08158e1c:
    if (*(char *)&(local_4d8.digest)->type == '\x06') {
      iVar4 = 0x9d;
LAB_08158f0c:
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar4);
LAB_08158de0:
      line = 0xf8;
      iVar4 = 0x7a;
    }
    else {
      if (*(char *)&(local_4d8.digest)->type != '\a') goto LAB_08158de0;
      if (*(char *)((int)&(local_4d8.digest)->type + 1) != '\x02') {
        ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
        goto LAB_08158de0;
      }
      uVar2 = (local_4d8.digest)->md_size;
      uVar3 = (local_4d8.digest)->flags;
      pp_Var1 = &(local_4d8.digest)->init;
      if (uVar2 == 0x31535344) {
LAB_08158f04:
        iVar4 = 0xba;
        goto LAB_08158f0c;
      }
      if (uVar2 < 0x31535345) {
        if (uVar2 != 0x31415352) {
LAB_08159018:
          ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
          goto LAB_08158de0;
        }
        goto LAB_08158f04;
      }
      if (uVar2 == 0x32415352) {
        if ((uVar3 + 0xf >> 4) * 5 + 4 + (uVar3 + 7 >> 3) * 2 <= param_3 - 0x10) {
          local_4d8.digest = (EVP_MD *)pp_Var1;
          uVar7 = b2i_rsa_isra_1();
          goto LAB_08158bce;
        }
      }
      else {
        if (uVar2 != 0x32535344) goto LAB_08159018;
        if ((uVar3 + 7 >> 3) * 2 + 0x40 <= param_3 - 0x10) {
          local_4d8.digest = (EVP_MD *)pp_Var1;
          uVar7 = b2i_dss_isra_0();
          goto LAB_08158bce;
        }
      }
      line = 0xfd;
      iVar4 = 0x7b;
      local_4d8.digest = (EVP_MD *)pp_Var1;
    }
    ERR_put_error(9,0x84,iVar4,"pvkfmt.c",line);
  }
  else {
    if (param_1 == (code *)0x0) {
      local_4e4 = PEM_def_callback(local_420,0x400,0,param_2);
    }
    else {
      local_4e4 = (*param_1)(local_420,0x400,0,param_2);
    }
    local_4e0 = local_420;
    if ((int)local_4e4 < 1) {
      bVar6 = false;
      ERR_put_error(9,0x87,0x68,"pvkfmt.c",0x2c2);
      local_4e8 = (EVP_MD *)0x0;
    }
    else {
      local_4e8 = (EVP_MD *)CRYPTO_malloc(param_3 + 8,"pvkfmt.c",0x2c5);
      if (local_4e8 == (EVP_MD *)0x0) {
        bVar6 = false;
        ERR_put_error(9,0x87,0x41,"pvkfmt.c",0x2c7);
      }
      else {
        EVP_MD_CTX_init(&local_4d8);
        type = EVP_sha1();
        iVar4 = EVP_DigestInit_ex(&local_4d8,type,(ENGINE *)0x0);
        if (iVar4 == 0) {
LAB_08158bbb:
          EVP_MD_CTX_cleanup(&local_4d8);
        }
        else {
          iVar4 = EVP_DigestUpdate(&local_4d8,param_1_00,param_2_00);
          if (iVar4 == 0) goto LAB_08158bbb;
          iVar4 = EVP_DigestUpdate(&local_4d8,local_4e0,local_4e4);
          if (iVar4 == 0) goto LAB_08158bbb;
          iVar4 = EVP_DigestFinal_ex(&local_4d8,local_434,(uint *)0x0);
          if (iVar4 == 0) goto LAB_08158bbb;
          piVar8 = (int *)((int)param_1_00->required_pkey_type + (param_2_00 - 0x2c));
          EVP_MD_CTX_cleanup(&local_4d8);
          iVar4 = piVar8[1];
          local_4e8->type = *piVar8;
          local_4e8->pkey_type = iVar4;
          if (param_3 < 8) {
            bVar6 = true;
            ERR_put_error(9,0x87,0x7d,"pvkfmt.c",0x2d2);
            goto LAB_08158bcc;
          }
          out = &local_4e8->md_size;
          pEVar5 = EVP_rc4();
          iVar4 = EVP_DecryptInit_ex(&local_4c0,pEVar5,(ENGINE *)0x0,local_434,(uchar *)0x0);
          if (iVar4 != 0) {
            iVar4 = EVP_DecryptUpdate(&local_4c0,(uchar *)out,(int *)&local_4d8,
                                      (uchar *)(piVar8 + 2),param_3 - 8);
            if (iVar4 != 0) {
              iVar4 = EVP_DecryptFinal_ex(&local_4c0,
                                          (uchar *)((int)out +
                                                   (int)((local_4d8.digest)->required_pkey_type +
                                                        -0xb)),(int *)&local_4d8);
              if (iVar4 != 0) {
                iVar4 = local_4e8->md_size;
                bVar6 = iVar4 != 0x32415352 && iVar4 != 0x32535344;
                if (iVar4 == 0x32415352 || iVar4 == 0x32535344) {
                  OPENSSL_cleanse(local_434,0x14);
LAB_08158dcc:
                  bVar6 = true;
                  local_4d8.digest = local_4e8;
                  if (0xf < param_3) goto LAB_08158e1c;
                  goto LAB_08158de0;
                }
                local_42f = 0;
                local_42b = 0;
                local_427 = 0;
                local_425 = 0;
                pEVar5 = EVP_rc4();
                iVar4 = EVP_DecryptInit_ex(&local_4c0,pEVar5,(ENGINE *)0x0,local_434,(uchar *)0x0);
                if (iVar4 != 0) {
                  OPENSSL_cleanse(local_434,0x14);
                  iVar4 = EVP_DecryptUpdate(&local_4c0,(uchar *)out,(int *)&local_4d8,
                                            (uchar *)(piVar8 + 2),param_3 - 8);
                  if (iVar4 != 0) {
                    iVar4 = EVP_DecryptFinal_ex(&local_4c0,
                                                (uchar *)((int)out +
                                                         (int)((local_4d8.digest)->
                                                               required_pkey_type + -0xb)),
                                                (int *)&local_4d8);
                    if (iVar4 != 0) {
                      iVar4 = local_4e8->md_size;
                      bVar6 = iVar4 != 0x32415352 && iVar4 != 0x32535344;
                      if (iVar4 == 0x32415352 || iVar4 == 0x32535344) goto LAB_08158dcc;
                      ERR_put_error(9,0x87,0x65,"pvkfmt.c",0x2ea);
                    }
                  }
                }
                goto LAB_08158bcc;
              }
            }
          }
        }
        bVar6 = true;
      }
    }
  }
LAB_08158bcc:
  uVar7 = 0;
LAB_08158bce:
  EVP_CIPHER_CTX_cleanup(&local_4c0);
  if (bVar6) {
    CRYPTO_free(local_4e8);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

