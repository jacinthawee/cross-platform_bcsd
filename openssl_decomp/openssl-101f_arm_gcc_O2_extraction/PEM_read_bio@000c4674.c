
int PEM_read_bio(BIO *bp,char **name,char **header,uchar **data,long *len)

{
  BUF_MEM *a;
  BUF_MEM *a_00;
  BUF_MEM *a_01;
  int iVar1;
  size_t sVar2;
  int iVar3;
  BUF_MEM *pBVar4;
  char *__s;
  int iVar5;
  bool bVar6;
  bool bVar7;
  int local_198;
  int local_194;
  EVP_ENCODE_CTX EStack_190;
  byte local_130 [9];
  byte abStack_127 [245];
  undefined local_32;
  int local_2c;
  
  local_194 = 0;
  local_2c = __TMC_END__;
  a = BUF_MEM_new();
  a_00 = BUF_MEM_new();
  a_01 = BUF_MEM_new();
  if ((a_00 == (BUF_MEM *)0x0 || a == (BUF_MEM *)0x0) || (a_01 == (BUF_MEM *)0x0)) {
    BUF_MEM_free(a);
    BUF_MEM_free(a_00);
    BUF_MEM_free(a_01);
    ERR_put_error(9,0x6d,0x41,"pem_lib.c",0x2b4);
    iVar1 = 0;
    goto LAB_000c4766;
  }
  local_32 = 0;
  do {
    do {
      iVar1 = BIO_gets(bp,(char *)local_130,0xfe);
      if (iVar1 < 1) {
        ERR_put_error(9,0x6d,0x6c,"pem_lib.c",0x2bf);
        goto LAB_000c4752;
      }
      do {
        if (0x20 < local_130[iVar1]) break;
        bVar6 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar6);
      local_130[iVar1 + 1] = 10;
      local_130[iVar1 + 2] = 0;
      iVar1 = strncmp((char *)local_130,"-----BEGIN ",0xb);
    } while (iVar1 != 0);
    sVar2 = strlen((char *)(abStack_127 + 2));
    iVar1 = strncmp((char *)(local_130 + sVar2 + 5),"-----\n",6);
  } while (iVar1 != 0);
  iVar3 = BUF_MEM_grow(a,sVar2 + 9);
  if (iVar3 == 0) {
    iVar3 = 0x2ce;
LAB_000c4742:
    ERR_put_error(9,0x6d,0x41,"pem_lib.c",iVar3);
  }
  else {
    memcpy(a->data,abStack_127 + 2,sVar2 - 6);
    a->data[sVar2 - 6] = '\0';
    iVar3 = BUF_MEM_grow(a_00,0x100);
    if (iVar3 == 0) {
      iVar3 = 0x2d8;
      goto LAB_000c4742;
    }
    *a_00->data = '\0';
    while (iVar3 = BIO_gets(bp,(char *)local_130,0xfe), 0 < iVar3) {
      do {
        if (0x20 < local_130[iVar3]) break;
        bVar6 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar6);
      sVar2 = iVar3 + 2;
      local_130[iVar3 + 1] = 10;
      local_130[sVar2] = 0;
      if (local_130[0] == 10) break;
      iVar5 = iVar1 + sVar2;
      iVar3 = BUF_MEM_grow(a_00,iVar5 + 9);
      if (iVar3 == 0) {
        iVar3 = 0x2e4;
        goto LAB_000c4742;
      }
      iVar3 = strncmp((char *)local_130,"-----END ",9);
      if (iVar3 == 0) {
        bVar6 = true;
        goto LAB_000c4874;
      }
      memcpy(a_00->data + iVar1,local_130,sVar2);
      a_00->data[iVar5] = '\0';
      iVar1 = iVar5;
    }
    bVar6 = false;
LAB_000c4874:
    local_194 = 0;
    iVar5 = BUF_MEM_grow(a_01,0x400);
    iVar3 = 0x2f1;
    if (iVar5 == 0) goto LAB_000c4742;
    *a_01->data = '\0';
    if (bVar6) {
      local_194 = iVar1;
      iVar1 = strncmp((char *)local_130,"-----END ",9);
      pBVar4 = a_01;
      a_01 = a_00;
    }
    else {
      do {
        iVar1 = BIO_gets(bp,(char *)local_130,0xfe);
        pBVar4 = a_00;
        if (iVar1 < 1) goto LAB_000c4a92;
        do {
          if (0x20 < local_130[iVar1]) {
            sVar2 = iVar1 + 2;
            local_130[iVar1 + 1] = 10;
            local_130[sVar2] = bVar6;
            if (sVar2 == 0x41) {
              iVar1 = strncmp((char *)local_130,"-----END ",9);
              if (iVar1 == 0) {
                __s = a->data;
                sVar2 = strlen(__s);
                goto LAB_000c49cc;
              }
              bVar7 = false;
            }
            else {
              iVar1 = strncmp((char *)local_130,"-----END ",9);
              if (iVar1 == 0) goto LAB_000c4ab0;
              if (0x41 < (int)sVar2) goto LAB_000c49da;
              bVar7 = true;
            }
            goto LAB_000c48e2;
          }
          bVar7 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar7);
        local_130[0] = 10;
        local_130[1] = bVar6;
        iVar1 = strncmp((char *)local_130,"-----END ",9);
        if (iVar1 == 0) {
LAB_000c4ab0:
          __s = a->data;
          sVar2 = strlen(__s);
          goto LAB_000c49cc;
        }
        sVar2 = 1;
        bVar7 = true;
LAB_000c48e2:
        iVar1 = BUF_MEM_grow_clean(a_01,sVar2 + local_194 + 9);
        if (iVar1 == 0) {
          iVar3 = 0x303;
          goto LAB_000c4742;
        }
        memcpy(a_01->data + local_194,local_130,sVar2);
        a_01->data[sVar2 + local_194] = bVar6;
        local_194 = local_194 + sVar2;
      } while (!bVar7);
      local_130[0] = 0;
      iVar1 = BIO_gets(bp,(char *)local_130,0xfe);
      if (iVar1 < 1) {
LAB_000c4a92:
        iVar1 = strncmp((char *)local_130,"-----END ",9);
      }
      else {
        do {
          if (0x20 < local_130[iVar1]) break;
          bVar6 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar6);
        local_130[iVar1 + 1] = 10;
        local_130[iVar1 + 2] = 0;
        iVar1 = strncmp((char *)local_130,"-----END ",9);
      }
    }
    __s = a->data;
    sVar2 = strlen(__s);
    a_00 = pBVar4;
    if (iVar1 == 0) {
LAB_000c49cc:
      iVar1 = strncmp(__s,(char *)abStack_127,sVar2);
      if ((iVar1 != 0) || (iVar1 = strncmp((char *)(local_130 + sVar2 + 9),"-----\n",6), iVar1 != 0)
         ) goto LAB_000c49da;
      EVP_DecodeInit(&EStack_190);
      iVar1 = EVP_DecodeUpdate(&EStack_190,(uchar *)a_01->data,&local_194,(uchar *)a_01->data,
                               local_194);
      if (iVar1 < 0) {
        iVar1 = 0x32c;
LAB_000c4ac6:
        ERR_put_error(9,0x6d,100,"pem_lib.c",iVar1);
      }
      else {
        iVar1 = EVP_DecodeFinal(&EStack_190,(uchar *)(a_01->data + local_194),&local_198);
        if (iVar1 < 0) {
          iVar1 = 0x332;
          goto LAB_000c4ac6;
        }
        local_194 = local_194 + local_198;
        if (local_194 != 0) {
          *name = a->data;
          *header = a_00->data;
          *data = (uchar *)a_01->data;
          *len = local_194;
          CRYPTO_free(a);
          CRYPTO_free(a_00);
          CRYPTO_free(a_01);
          iVar1 = 1;
          goto LAB_000c4766;
        }
      }
    }
    else {
LAB_000c49da:
      ERR_put_error(9,0x6d,0x66,"pem_lib.c",0x322);
    }
  }
LAB_000c4752:
  BUF_MEM_free(a);
  BUF_MEM_free(a_00);
  BUF_MEM_free(a_01);
  iVar1 = 0;
LAB_000c4766:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

