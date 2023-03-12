
void do_passwd(int param_1,byte **param_2,byte **param_3,byte *param_4,BIO *param_5,int param_6,
              uint param_7,int param_8,uint param_9,int param_10,uint param_11,uint param_12)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte *d;
  byte *pbVar12;
  int iVar13;
  size_t sVar14;
  size_t sVar15;
  size_t cnt;
  EVP_MD *pEVar16;
  undefined4 uVar17;
  byte *extraout_r1;
  char *__s;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  EVP_MD_CTX EStack_7c;
  EVP_MD_CTX EStack_64;
  byte local_4c;
  byte local_4b;
  byte local_4a;
  byte local_49;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_44;
  byte local_43;
  byte local_42;
  byte local_41;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_2 == (byte **)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("salt_p != NULL","passwd.c",0x1a7,PTR___PRETTY_FUNCTION___18701_0001a74c);
  }
  if (param_3 == (byte **)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("salt_malloc_p != NULL","passwd.c",0x1a8,PTR___PRETTY_FUNCTION___18701_0001a74c);
  }
  if (param_1 == 0) {
    if (param_10 != 0) {
      if (*param_3 == (byte *)0x0) {
        pbVar12 = (byte *)CRYPTO_malloc(3,"passwd.c",0x1b2);
        *param_3 = pbVar12;
        *param_2 = pbVar12;
        if (*param_3 != (byte *)0x0) goto LAB_00019f9a;
      }
      else {
        pbVar12 = *param_2;
LAB_00019f9a:
        iVar13 = RAND_pseudo_bytes(pbVar12,2);
        if (-1 < iVar13) {
          **param_2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
                      [**param_2 & 0x3f];
          (*param_2)[1] =
               "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
               [(*param_2)[1] & 0x3f];
          (*param_2)[2] = 0;
          goto LAB_00019fd0;
        }
      }
LAB_0001a648:
      uVar17 = 0;
      goto LAB_0001a596;
    }
LAB_00019fd0:
    if ((param_11 | param_12) != 0) {
      if (*param_3 == (byte *)0x0) {
        pbVar12 = (byte *)CRYPTO_malloc(9,"passwd.c",0x1c9);
        *param_3 = pbVar12;
        *param_2 = pbVar12;
        if (*param_3 == (byte *)0x0) goto LAB_0001a648;
      }
      else {
        pbVar12 = *param_2;
      }
      iVar13 = RAND_pseudo_bytes(pbVar12,8);
      if (iVar13 < 0) goto LAB_0001a648;
      **param_2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
                  [**param_2 & 0x3f];
      (*param_2)[1] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[1] & 0x3f];
      (*param_2)[2] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[2] & 0x3f];
      (*param_2)[3] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[3] & 0x3f];
      (*param_2)[4] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[4] & 0x3f];
      (*param_2)[5] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[5] & 0x3f];
      (*param_2)[6] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[6] & 0x3f];
      (*param_2)[7] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
           [(*param_2)[7] & 0x3f];
      (*param_2)[8] = 0;
    }
  }
  if (*param_2 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("*salt_p != NULL","passwd.c",0x1d7,PTR___PRETTY_FUNCTION___18701_0001a74c);
  }
  sVar14 = strlen((char *)param_4);
  if (param_9 < sVar14) {
    if (param_6 == 0) {
      BIO_printf(bio_err,"Warning: truncating password to %u characters\n",param_9);
    }
    param_4[param_9] = 0;
    sVar14 = strlen((char *)param_4);
    if (param_9 < sVar14) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(passwd) <= pw_maxlen","passwd.c",0x1e1,
                    PTR___PRETTY_FUNCTION___18701_0001a74c);
    }
  }
  if (param_10 == 0) {
    if ((param_11 | param_12) == 0) {
LAB_0001a5de:
                    /* WARNING: Subroutine does not return */
      __assert_fail("hash != NULL","passwd.c",0x1ec,PTR___PRETTY_FUNCTION___18701_0001a74c);
    }
LAB_0001a0ac:
    pcVar20 = "1";
    if (param_11 == 0) {
      pcVar20 = "apr1";
    }
    sVar14 = strlen((char *)param_4);
    pbVar12 = *param_2;
    out_buf_18657 = 0x24;
    DAT_001962ad = 0;
    __strncat_chk(&out_buf_18657,pcVar20,4,0x29);
    __strcat_chk(&out_buf_18657,&DAT_0012817c,0x29);
    __strncat_chk(&out_buf_18657,pbVar12,8,0x29);
    sVar15 = strlen(&out_buf_18657);
    if (0xe < sVar15) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(out_buf) <= 6 + 8","passwd.c",0x147,
                    PTR___PRETTY_FUNCTION___18666_0001a750);
    }
    sVar15 = strlen(pcVar20);
    __s = (char *)(sVar15 + 0x1962ae);
    cnt = strlen(__s);
    if (8 < cnt) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("salt_len <= 8","passwd.c",0x14a,PTR___PRETTY_FUNCTION___18666_0001a750);
    }
    EVP_MD_CTX_init(&EStack_7c);
    pEVar16 = EVP_md5();
    EVP_DigestInit_ex(&EStack_7c,pEVar16,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_7c,param_4,sVar14);
    EVP_DigestUpdate(&EStack_7c,&DAT_0012817c,1);
    EVP_DigestUpdate(&EStack_7c,pcVar20,sVar15);
    EVP_DigestUpdate(&EStack_7c,&DAT_0012817c,1);
    EVP_DigestUpdate(&EStack_7c,__s,cnt);
    EVP_MD_CTX_init(&EStack_64);
    pEVar16 = EVP_md5();
    EVP_DigestInit_ex(&EStack_64,pEVar16,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_64,param_4,sVar14);
    EVP_DigestUpdate(&EStack_64,__s,cnt);
    EVP_DigestUpdate(&EStack_64,param_4,sVar14);
    EVP_DigestFinal_ex(&EStack_64,&local_4c,(uint *)0x0);
    sVar15 = sVar14;
    uVar18 = sVar14;
    if (0x10 < sVar14) {
      do {
        uVar18 = uVar18 - 0x10;
        EVP_DigestUpdate(&EStack_7c,&local_4c,0x10);
      } while (0x10 < uVar18);
      sVar15 = (sVar14 - 0x10) - (sVar14 - 0x11 & 0xfffffff0);
    }
    EVP_DigestUpdate(&EStack_7c,&local_4c,sVar15);
    for (uVar18 = sVar14; uVar18 != 0; uVar18 = (int)uVar18 >> 1) {
      pbVar12 = param_4;
      if ((uVar18 & 1) != 0) {
        pbVar12 = &UNK_00128050;
      }
      EVP_DigestUpdate(&EStack_7c,pbVar12,1);
    }
    EVP_DigestFinal_ex(&EStack_7c,&local_4c,(uint *)0x0);
    uVar18 = 0;
    do {
      pEVar16 = EVP_md5();
      EVP_DigestInit_ex(&EStack_64,pEVar16,(ENGINE *)0x0);
      uVar19 = uVar18 & 1;
      pbVar12 = extraout_r1;
      if (uVar19 == 0) {
        pbVar12 = &local_4c;
      }
      sVar15 = sVar14;
      d = param_4;
      if (uVar19 == 0) {
        sVar15 = 0x10;
        d = pbVar12;
      }
      EVP_DigestUpdate(&EStack_64,d,sVar15);
      if (uVar18 != uVar18 / 3 + ((uint)((ulonglong)uVar18 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) {
        EVP_DigestUpdate(&EStack_64,__s,cnt);
      }
      if (uVar18 != (uVar18 / 7) * 7) {
        EVP_DigestUpdate(&EStack_64,param_4,sVar14);
      }
      pbVar12 = param_4;
      sVar15 = sVar14;
      if (uVar19 != 0) {
        pbVar12 = &local_4c;
        sVar15 = 0x10;
      }
      uVar18 = uVar18 + 1;
      EVP_DigestUpdate(&EStack_64,pbVar12,sVar15);
      EVP_DigestFinal_ex(&EStack_64,&local_4c,(uint *)0x0);
    } while (uVar18 != 1000);
    pcVar20 = __s + cnt;
    EVP_MD_CTX_cleanup(&EStack_64);
    local_3c = local_4c;
    local_3b = local_46;
    local_3a = local_40;
    local_39 = local_4b;
    local_38 = local_45;
    local_37 = local_3f;
    local_36 = local_4a;
    local_35 = local_44;
    local_34 = local_3e;
    local_33 = local_49;
    local_31 = local_3d;
    local_30 = local_48;
    local_32 = local_43;
    local_2f = local_42;
    local_2e = local_47;
    sVar14 = strlen(&out_buf_18657);
    if (pcVar20 != &out_buf_18657 + sVar14) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("output == out_buf + strlen(out_buf)","passwd.c",0x187,
                    PTR___PRETTY_FUNCTION___18666_0001a750);
    }
    cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(local_39 & 3) << 4 | (uint)(local_38 >> 4)];
    cVar6 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_37 >> 6) | (local_38 & 0xf) << 2];
    __s[cnt] = '$';
    cVar7 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_36 >> 2];
    pcVar20[6] = cVar6;
    cVar8 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_37 & 0x3f];
    cVar9 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(local_36 & 3) << 4 | (uint)(local_35 >> 4)];
    cVar6 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_3a & 0x3f];
    cVar10 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
             [local_34 & 0x3f];
    cVar11 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
             [local_39 >> 2];
    cVar2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_3a >> 6) | (local_3b & 0xf) << 2];
    cVar3 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_3b >> 4) | (local_3c & 3) << 4];
    cVar4 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_3c >> 2];
    cVar5 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_34 >> 6) | (local_35 & 0xf) << 2];
    pcVar20[7] = cVar1;
    pcVar20[5] = cVar8;
    pcVar20[9] = cVar10;
    pcVar20[0xb] = cVar9;
    pcVar20[8] = cVar11;
    pcVar20[2] = cVar2;
    pcVar20[0xc] = cVar7;
    cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_33 >> 2];
    pcVar20[1] = cVar6;
    pcVar20[10] = cVar5;
    pcVar20[4] = cVar4;
    cVar5 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(local_33 & 3) << 4 | (uint)(local_32 >> 4)];
    cVar7 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_31 >> 6) | (local_32 & 0xf) << 2];
    cVar8 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_30 >> 2];
    cVar6 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(uint)(local_2e >> 6) | (local_2f & 0xf) << 2];
    cVar9 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_41 & 0x3f];
    cVar10 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
             [local_31 & 0x3f];
    cVar2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [(local_30 & 3) << 4 | (uint)(local_2f >> 4)];
    cVar4 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
            [local_2e & 0x3f];
    cVar11 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzmd5crypt"
             [local_41 >> 6];
    pcVar20[3] = cVar3;
    pcVar20[0x10] = cVar1;
    pcVar20[0xf] = cVar5;
    pcVar20[0xd] = cVar10;
    pcVar20[0xe] = cVar7;
    pcVar20[0x14] = cVar8;
    pcVar20[0x13] = cVar2;
    pcVar20[0x12] = cVar6;
    pcVar20[0x11] = cVar4;
    pcVar20[0x15] = cVar9;
    pcVar20[0x16] = cVar11;
    pcVar20[0x17] = '\0';
    sVar14 = strlen(&out_buf_18657);
    if (0x28 < sVar14) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(out_buf) < sizeof(out_buf)","passwd.c",0x198,"md5crypt");
    }
    EVP_MD_CTX_cleanup(&EStack_7c);
    pcVar20 = &out_buf_18657;
  }
  else {
    pcVar20 = DES_crypt((char *)param_4,(char *)*param_2);
    if ((param_11 | param_12) != 0) goto LAB_0001a0ac;
    if (pcVar20 == (char *)0x0) goto LAB_0001a5de;
  }
  if (param_7 != 0) {
    param_7 = 1;
  }
  if (param_8 == 0) {
    uVar18 = param_7 & 1;
  }
  else {
    uVar18 = 0;
  }
  if (uVar18 == 0) {
    if (param_8 == 0) {
      param_7 = 0;
    }
    else {
      param_7 = param_7 & 1;
    }
    if (param_7 == 0) {
      BIO_printf(param_5,"%s\n",pcVar20);
      uVar17 = 1;
    }
    else {
      BIO_printf(param_5,"%s\t%s\n",pcVar20,param_4);
      uVar17 = 1;
    }
  }
  else {
    BIO_printf(param_5,"%s\t%s\n",param_4);
    uVar17 = 1;
  }
LAB_0001a596:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar17);
  }
  return;
}

