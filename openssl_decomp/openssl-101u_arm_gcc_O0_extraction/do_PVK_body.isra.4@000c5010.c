
void do_PVK_body_isra_4(EVP_MD *param_1,EVP_MD *param_2,uint param_3,code *param_4,void *param_5)

{
  size_t cnt;
  EVP_MD *ptr;
  EVP_MD *pEVar1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
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
  
  local_2c = __stack_chk_guard;
  EVP_CIPHER_CTX_init(&EStack_4b8);
  pEVar1 = param_1;
  ptr = param_2;
  if (param_2 != (EVP_MD *)0x0) {
    if (param_4 == (code *)0x0) {
      cnt = PEM_def_callback(acStack_42c,0x400,0,param_5);
    }
    else {
      cnt = (*param_4)(acStack_42c,0x400,0,param_5);
    }
    if ((int)cnt < 1) {
      param_2 = (EVP_MD *)0x0;
      ERR_put_error(9,0x87,0x68,"pvkfmt.c",0x2c2);
      ptr = (EVP_MD *)0x0;
    }
    else {
      ptr = (EVP_MD *)CRYPTO_malloc(param_3 + 8,"pvkfmt.c",0x2c5);
      if (ptr == (EVP_MD *)0x0) {
        ERR_put_error(9,0x87,0x41,"pvkfmt.c",0x2c7);
        param_2 = ptr;
      }
      else {
        EVP_MD_CTX_init(&local_4e4);
        pEVar1 = EVP_sha1();
        iVar2 = EVP_DigestInit_ex(&local_4e4,pEVar1,(ENGINE *)0x0);
        if ((((iVar2 == 0) ||
             (iVar2 = EVP_DigestUpdate(&local_4e4,param_1,(size_t)param_2), iVar2 == 0)) ||
            (iVar2 = EVP_DigestUpdate(&local_4e4,acStack_42c,cnt), iVar2 == 0)) ||
           (iVar2 = EVP_DigestFinal_ex(&local_4e4,auStack_4cc,(uint *)0x0), iVar2 == 0)) {
          EVP_MD_CTX_cleanup(&local_4e4);
          param_2 = (EVP_MD *)0x1;
        }
        else {
          piVar6 = (int *)((int)param_1->required_pkey_type +
                          (int)(param_2->required_pkey_type + -0x16));
          EVP_MD_CTX_cleanup(&local_4e4);
          iVar2 = piVar6[1];
          ptr->type = *piVar6;
          ptr->pkey_type = iVar2;
          if (param_3 < 8) {
            ERR_put_error(9,0x87,0x7d,"pvkfmt.c",0x2d2);
            param_2 = (EVP_MD *)0x1;
          }
          else {
            pEVar3 = EVP_rc4();
            out = &ptr->md_size;
            iVar2 = EVP_DecryptInit_ex(&EStack_4b8,pEVar3,(ENGINE *)0x0,auStack_4cc,(uchar *)0x0);
            if (((iVar2 == 0) ||
                (iVar2 = EVP_DecryptUpdate(&EStack_4b8,(uchar *)out,(int *)&local_4e4,
                                           (uchar *)(piVar6 + 2),param_3 - 8), iVar2 == 0)) ||
               (iVar2 = EVP_DecryptFinal_ex(&EStack_4b8,
                                            (uchar *)((int)out +
                                                     (int)((local_4e4.digest)->required_pkey_type +
                                                          -0xb)),(int *)&local_4e4), iVar2 == 0)) {
              param_2 = (EVP_MD *)0x1;
            }
            else {
              uVar7 = (uint)*(byte *)((int)&ptr->md_size + 2) << 0x10 |
                      (uint)*(byte *)((int)&ptr->md_size + 1) << 8 | (uint)*(byte *)&ptr->md_size |
                      (uint)*(byte *)((int)&ptr->md_size + 3) << 0x18;
              if (uVar7 == 0x32535344 || uVar7 == 0x32415352) {
                OPENSSL_cleanse(auStack_4cc,0x14);
LAB_000c5228:
                param_2 = (EVP_MD *)0x1;
                pEVar1 = ptr;
                goto joined_r0x000c5236;
              }
              param_2 = (EVP_MD *)0x1;
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
              iVar2 = EVP_DecryptInit_ex(&EStack_4b8,pEVar3,(ENGINE *)0x0,auStack_4cc,(uchar *)0x0);
              if (iVar2 != 0) {
                OPENSSL_cleanse(auStack_4cc,0x14);
                iVar2 = EVP_DecryptUpdate(&EStack_4b8,(uchar *)out,(int *)&local_4e4,
                                          (uchar *)(piVar6 + 2),param_3 - 8);
                if ((iVar2 != 0) &&
                   (iVar2 = EVP_DecryptFinal_ex(&EStack_4b8,
                                                (uchar *)((int)out +
                                                         (int)((local_4e4.digest)->
                                                               required_pkey_type + -0xb)),
                                                (int *)&local_4e4), iVar2 != 0)) {
                  uVar7 = (uint)*(byte *)((int)&ptr->md_size + 2) << 0x10 |
                          (uint)*(byte *)((int)&ptr->md_size + 1) << 8 |
                          (uint)*(byte *)&ptr->md_size |
                          (uint)*(byte *)((int)&ptr->md_size + 3) << 0x18;
                  if (uVar7 == 0x32535344 || uVar7 == 0x32415352) goto LAB_000c5228;
                  ERR_put_error(9,0x87,0x65,"pvkfmt.c",0x2ea);
                  param_2 = (EVP_MD *)0x1;
                }
              }
            }
          }
        }
      }
    }
    uVar5 = 0;
    goto LAB_000c509c;
  }
joined_r0x000c5236:
  local_4e4.digest = pEVar1;
  if (0xf < param_3) {
    if (*(char *)&(local_4e4.digest)->type == '\x06') {
      iVar2 = 0x9d;
LAB_000c5338:
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar2);
    }
    else if (*(char *)&(local_4e4.digest)->type == '\a') {
      if (*(char *)((int)&(local_4e4.digest)->type + 1) == '\x02') {
        uVar4 = (uint)*(byte *)((int)&(local_4e4.digest)->md_size + 2) << 0x10 |
                (uint)*(byte *)((int)&(local_4e4.digest)->md_size + 1) << 8 |
                (uint)*(byte *)&(local_4e4.digest)->md_size |
                (uint)*(byte *)((int)&(local_4e4.digest)->md_size + 3) << 0x18;
        uVar7 = (uint)*(byte *)((int)&(local_4e4.digest)->flags + 2) << 0x10 |
                (uint)*(byte *)((int)&(local_4e4.digest)->flags + 1) << 8 |
                (uint)*(byte *)&(local_4e4.digest)->flags |
                (uint)*(byte *)((int)&(local_4e4.digest)->flags + 3) << 0x18;
        if (uVar4 != 0x31535344) {
          if (0x31535344 < uVar4) {
            if (uVar4 == 0x32415352) {
              if ((uVar7 + 0xf >> 4) * 5 + ((uVar7 + 7 >> 3) + 2) * 2 <= param_3 - 0x10) {
                local_4e4.digest = (EVP_MD *)&(local_4e4.digest)->init;
                uVar5 = b2i_rsa_isra_1(&local_4e4,uVar7,0);
                goto LAB_000c509c;
              }
            }
            else {
              if (uVar4 != 0x32535344) goto LAB_000c53c0;
              if (((uVar7 + 7 >> 3) + 0x20) * 2 <= param_3 - 0x10) {
                local_4e4.digest = (EVP_MD *)&(local_4e4.digest)->init;
                uVar5 = b2i_dss_isra_0(&local_4e4,uVar7,0);
                goto LAB_000c509c;
              }
            }
            local_4e4.digest = (EVP_MD *)&(local_4e4.digest)->init;
            uVar5 = 0;
            ERR_put_error(9,0x84,0x7b,"pvkfmt.c",0xfd);
            goto LAB_000c509c;
          }
          if (uVar4 != 0x31415352) {
LAB_000c53c0:
            ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
            goto LAB_000c5238;
          }
        }
        iVar2 = 0xba;
        goto LAB_000c5338;
      }
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
    }
  }
LAB_000c5238:
  uVar5 = 0;
  ERR_put_error(9,0x84,0x7a,"pvkfmt.c",0xf8);
LAB_000c509c:
  EVP_CIPHER_CTX_cleanup(&EStack_4b8);
  if (param_2 != (EVP_MD *)0x0) {
    CRYPTO_free(ptr);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}

