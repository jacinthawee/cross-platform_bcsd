
void do_PVK_body_isra_4(EVP_MD *param_1,EVP_MD *param_2,uint param_3,code *param_4,void *param_5)

{
  size_t cnt;
  EVP_MD *ptr;
  EVP_MD *type;
  int iVar1;
  undefined4 uVar2;
  EVP_CIPHER *pEVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *out;
  EVP_MD_CTX local_4e4;
  uchar auStack_4cc [5];
  undefined local_4c7;
  undefined local_4c6;
  undefined local_4c5;
  undefined local_4c4;
  undefined local_4c3;
  undefined local_4c2;
  undefined local_4c1;
  undefined local_4c0;
  undefined local_4bf;
  undefined local_4be;
  undefined local_4bd;
  EVP_CIPHER_CTX EStack_4b8;
  char acStack_42c [1024];
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_CIPHER_CTX_init(&EStack_4b8);
  ptr = param_2;
  if (param_2 == (EVP_MD *)0x0) {
LAB_000c771e:
    local_4e4.digest = param_1;
    if (param_3 < 0x10) goto LAB_000c77d6;
    if (*(char *)&param_1->type == '\x06') {
      iVar1 = 0x98;
LAB_000c77c6:
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar1);
LAB_000c77d6:
      uVar2 = 0;
      ERR_put_error(9,0x84,0x7a,"pvkfmt.c",0xff);
    }
    else {
      if (*(char *)&param_1->type != '\a') goto LAB_000c77d6;
      if (*(char *)((int)&param_1->type + 1) != '\x02') {
        ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
        goto LAB_000c77d6;
      }
      uVar5 = (uint)*(byte *)((int)&param_1->md_size + 2) << 0x10 |
              (uint)*(byte *)((int)&param_1->md_size + 1) << 8 | (uint)*(byte *)&param_1->md_size |
              (uint)*(byte *)((int)&param_1->md_size + 3) << 0x18;
      uVar4 = (uint)*(byte *)((int)&param_1->flags + 2) << 0x10 |
              (uint)*(byte *)((int)&param_1->flags + 1) << 8 | (uint)*(byte *)&param_1->flags |
              (uint)*(byte *)((int)&param_1->flags + 3) << 0x18;
      if (uVar5 == 0x31535344) {
LAB_000c77c0:
        iVar1 = 0xbe;
        goto LAB_000c77c6;
      }
      if (uVar5 < 0x31535345) {
        if (uVar5 != 0x31415352) {
LAB_000c794e:
          ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
          goto LAB_000c77d6;
        }
        goto LAB_000c77c0;
      }
      if (uVar5 == 0x32415352) {
        local_4e4.digest = (EVP_MD *)&param_1->init;
        if (param_3 - 0x10 < (uVar4 + 0xf >> 4) * 5 + ((uVar4 + 7 >> 3) + 2) * 2) {
LAB_000c79b6:
          local_4e4.digest = (EVP_MD *)&param_1->init;
          uVar2 = 0;
          ERR_put_error(9,0x84,0x7b,"pvkfmt.c",0x105);
        }
        else {
          uVar2 = b2i_rsa_isra_1(&local_4e4,uVar4,0);
        }
      }
      else {
        if (uVar5 != 0x32535344) goto LAB_000c794e;
        local_4e4.digest = (EVP_MD *)&param_1->init;
        if (param_3 - 0x10 < ((uVar4 + 7 >> 3) + 0x20) * 2) goto LAB_000c79b6;
        uVar2 = b2i_dss_isra_0(&local_4e4,uVar4,0);
      }
    }
    EVP_CIPHER_CTX_cleanup(&EStack_4b8);
    if (param_2 == (EVP_MD *)0x0) goto LAB_000c7692;
LAB_000c7710:
    CRYPTO_free(ptr);
  }
  else {
    if (param_4 == (code *)0x0) {
      cnt = PEM_def_callback(acStack_42c,0x400,0,param_5);
    }
    else {
      cnt = (*param_4)(acStack_42c,0x400,0,param_5);
    }
    if ((int)cnt < 1) {
      ERR_put_error(9,0x87,0x68,"pvkfmt.c",0x2ea);
    }
    else {
      ptr = (EVP_MD *)CRYPTO_malloc(param_3 + 8,"pvkfmt.c",0x2ed);
      if (ptr == (EVP_MD *)0x0) {
        ERR_put_error(9,0x87,0x41,"pvkfmt.c",0x2f0);
      }
      else {
        EVP_MD_CTX_init(&local_4e4);
        type = EVP_sha1();
        iVar1 = EVP_DigestInit_ex(&local_4e4,type,(ENGINE *)0x0);
        if ((((iVar1 != 0) &&
             (iVar1 = EVP_DigestUpdate(&local_4e4,param_1,(size_t)param_2), iVar1 != 0)) &&
            (iVar1 = EVP_DigestUpdate(&local_4e4,acStack_42c,cnt), iVar1 != 0)) &&
           (iVar1 = EVP_DigestFinal_ex(&local_4e4,auStack_4cc,(uint *)0x0), iVar1 != 0)) {
          piVar6 = (int *)((int)param_2->required_pkey_type +
                          (int)(param_1->required_pkey_type + -0x16));
          EVP_MD_CTX_cleanup(&local_4e4);
          iVar1 = piVar6[1];
          out = &ptr->md_size;
          ptr->type = *piVar6;
          ptr->pkey_type = iVar1;
          pEVar3 = EVP_rc4();
          iVar1 = EVP_DecryptInit_ex(&EStack_4b8,pEVar3,(ENGINE *)0x0,auStack_4cc,(uchar *)0x0);
          if (((iVar1 != 0) &&
              (iVar1 = EVP_DecryptUpdate(&EStack_4b8,(uchar *)out,(int *)&local_4e4,
                                         (uchar *)(piVar6 + 2),param_3 - 8), iVar1 != 0)) &&
             (iVar1 = EVP_DecryptFinal_ex(&EStack_4b8,
                                          (uchar *)((int)out +
                                                   (int)((local_4e4.digest)->required_pkey_type +
                                                        -0xb)),(int *)&local_4e4), iVar1 != 0)) {
            uVar4 = (uint)*(byte *)((int)&ptr->md_size + 2) << 0x10 |
                    (uint)*(byte *)((int)&ptr->md_size + 1) << 8 | (uint)*(byte *)&ptr->md_size |
                    (uint)*(byte *)((int)&ptr->md_size + 3) << 0x18;
            if (uVar4 == 0x32535344 || uVar4 == 0x32415352) {
              OPENSSL_cleanse(auStack_4cc,0x14);
LAB_000c790c:
              param_2 = (EVP_MD *)0x1;
              param_1 = ptr;
              goto LAB_000c771e;
            }
            local_4c7 = 0;
            local_4c6 = 0;
            local_4c5 = 0;
            local_4c4 = 0;
            local_4c3 = 0;
            local_4c2 = 0;
            local_4c1 = 0;
            local_4c0 = 0;
            local_4bf = 0;
            local_4be = 0;
            local_4bd = 0;
            pEVar3 = EVP_rc4();
            iVar1 = EVP_DecryptInit_ex(&EStack_4b8,pEVar3,(ENGINE *)0x0,auStack_4cc,(uchar *)0x0);
            if (iVar1 != 0) {
              OPENSSL_cleanse(auStack_4cc,0x14);
              iVar1 = EVP_DecryptUpdate(&EStack_4b8,(uchar *)out,(int *)&local_4e4,
                                        (uchar *)(piVar6 + 2),param_3 - 8);
              if ((iVar1 != 0) &&
                 (iVar1 = EVP_DecryptFinal_ex(&EStack_4b8,
                                              (uchar *)((int)out +
                                                       (int)((local_4e4.digest)->required_pkey_type
                                                            + -0xb)),(int *)&local_4e4), iVar1 != 0)
                 ) {
                uVar4 = (uint)*(byte *)&ptr->md_size |
                        (uint)*(byte *)((int)&ptr->md_size + 2) << 0x10 |
                        (uint)*(byte *)((int)&ptr->md_size + 1) << 8 |
                        (uint)*(byte *)((int)&ptr->md_size + 3) << 0x18;
                if ((uVar4 == 0x32535344) || (uVar4 == 0x32415352)) goto LAB_000c790c;
                ERR_put_error(9,0x87,0x65,"pvkfmt.c",0x313);
              }
            }
          }
          uVar2 = 0;
          EVP_CIPHER_CTX_cleanup(&EStack_4b8);
          goto LAB_000c7710;
        }
        EVP_MD_CTX_cleanup(&local_4e4);
      }
    }
    uVar2 = 0;
  }
LAB_000c7692:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

