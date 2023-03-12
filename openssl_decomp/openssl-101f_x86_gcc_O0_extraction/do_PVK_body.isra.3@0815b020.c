
undefined4 __regparm3
do_PVK_body_isra_3(EVP_MD *param_1_00,size_t param_2_00,uint param_3,code *param_1,void *param_2)

{
  int *out;
  uint uVar1;
  ulong uVar2;
  bool bVar3;
  EVP_MD *type;
  int iVar4;
  undefined4 uVar5;
  EVP_CIPHER *pEVar6;
  int *piVar7;
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
    bVar3 = false;
    local_4e8 = (EVP_MD *)0x0;
LAB_0815b1ba:
    local_4d8.digest = param_1_00;
    if (param_3 < 0x10) goto LAB_0815b260;
    if (*(char *)&param_1_00->type == '\x06') {
      iVar4 = 0x98;
LAB_0815b248:
      local_4d8.digest = param_1_00;
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar4);
LAB_0815b260:
      line = 0xff;
      iVar4 = 0x7a;
LAB_0815b26f:
      uVar5 = 0;
      ERR_put_error(9,0x84,iVar4,"pvkfmt.c",line);
    }
    else {
      if (*(char *)&param_1_00->type != '\a') goto LAB_0815b260;
      if (*(char *)((int)&param_1_00->type + 1) != '\x02') {
        ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
        goto LAB_0815b260;
      }
      uVar1 = param_1_00->md_size;
      uVar2 = param_1_00->flags;
      local_4d8.digest = (EVP_MD *)&param_1_00->init;
      if (uVar1 == 0x31535344) {
LAB_0815b240:
        iVar4 = 0xbe;
        goto LAB_0815b248;
      }
      if (uVar1 < 0x31535345) {
        if (uVar1 != 0x31415352) {
LAB_0815b49c:
          local_4d8.digest = param_1_00;
          ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
          goto LAB_0815b260;
        }
        goto LAB_0815b240;
      }
      if (uVar1 == 0x32415352) {
        if ((uVar2 + 0xf >> 4) * 5 + 4 + (uVar2 + 7 >> 3) * 2 <= param_3 - 0x10) {
          uVar5 = b2i_rsa_isra_1();
          goto LAB_0815b280;
        }
LAB_0815b4e5:
        line = 0x105;
        iVar4 = 0x7b;
        goto LAB_0815b26f;
      }
      if (uVar1 != 0x32535344) goto LAB_0815b49c;
      if (param_3 - 0x10 < (uVar2 + 7 >> 3) * 2 + 0x40) goto LAB_0815b4e5;
      uVar5 = b2i_dss_isra_0();
    }
LAB_0815b280:
    EVP_CIPHER_CTX_cleanup(&local_4c0);
    if (!bVar3) goto LAB_0815b296;
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
      ERR_put_error(9,0x87,0x68,"pvkfmt.c",0x2ea);
      uVar5 = 0;
      goto LAB_0815b296;
    }
    local_4e8 = (EVP_MD *)CRYPTO_malloc(param_3 + 8,"pvkfmt.c",0x2ed);
    if (local_4e8 == (EVP_MD *)0x0) {
      ERR_put_error(9,0x87,0x41,"pvkfmt.c",0x2f0);
      uVar5 = 0;
      goto LAB_0815b296;
    }
    EVP_MD_CTX_init(&local_4d8);
    type = EVP_sha1();
    iVar4 = EVP_DigestInit_ex(&local_4d8,type,(ENGINE *)0x0);
    if ((((iVar4 == 0) || (iVar4 = EVP_DigestUpdate(&local_4d8,param_1_00,param_2_00), iVar4 == 0))
        || (iVar4 = EVP_DigestUpdate(&local_4d8,local_4e0,local_4e4), iVar4 == 0)) ||
       (iVar4 = EVP_DigestFinal_ex(&local_4d8,local_434,(uint *)0x0), iVar4 == 0)) {
      EVP_MD_CTX_cleanup(&local_4d8);
      uVar5 = 0;
      goto LAB_0815b296;
    }
    piVar7 = (int *)((int)param_1_00->required_pkey_type + (param_2_00 - 0x2c));
    EVP_MD_CTX_cleanup(&local_4d8);
    iVar4 = *piVar7;
    local_4e8->pkey_type = piVar7[1];
    local_4e8->type = iVar4;
    pEVar6 = EVP_rc4();
    iVar4 = EVP_DecryptInit_ex(&local_4c0,pEVar6,(ENGINE *)0x0,local_434,(uchar *)0x0);
    if (iVar4 != 0) {
      out = &local_4e8->md_size;
      iVar4 = EVP_DecryptUpdate(&local_4c0,(uchar *)out,(int *)&local_4d8,(uchar *)(piVar7 + 2),
                                param_3 - 8);
      if ((iVar4 != 0) &&
         (iVar4 = EVP_DecryptFinal_ex(&local_4c0,
                                      (uchar *)((int)out +
                                               (int)((local_4d8.digest)->required_pkey_type + -0xb))
                                      ,(int *)&local_4d8), iVar4 != 0)) {
        if ((local_4e8->md_size == 0x32415352) || (local_4e8->md_size == 0x32535344)) {
          OPENSSL_cleanse(local_434,0x14);
LAB_0815b430:
          bVar3 = true;
          param_1_00 = local_4e8;
          goto LAB_0815b1ba;
        }
        local_42f = 0;
        local_42b = 0;
        local_427 = 0;
        local_425 = 0;
        pEVar6 = EVP_rc4();
        iVar4 = EVP_DecryptInit_ex(&local_4c0,pEVar6,(ENGINE *)0x0,local_434,(uchar *)0x0);
        if (iVar4 != 0) {
          OPENSSL_cleanse(local_434,0x14);
          iVar4 = EVP_DecryptUpdate(&local_4c0,(uchar *)out,(int *)&local_4d8,(uchar *)(piVar7 + 2),
                                    param_3 - 8);
          if ((iVar4 != 0) &&
             (iVar4 = EVP_DecryptFinal_ex(&local_4c0,(uchar *)((int)out + (int)local_4d8.digest),
                                          (int *)&local_4d8), iVar4 != 0)) {
            if ((local_4e8->md_size == 0x32415352) || (local_4e8->md_size == 0x32535344))
            goto LAB_0815b430;
            ERR_put_error(9,0x87,0x65,"pvkfmt.c",0x313);
          }
        }
      }
    }
    uVar5 = 0;
    EVP_CIPHER_CTX_cleanup(&local_4c0);
  }
  CRYPTO_free(local_4e8);
LAB_0815b296:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

