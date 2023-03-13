
undefined4 __regparm3
do_passwd(int param_1_00,byte **param_2_00,byte **param_3_00,byte *param_1,BIO *param_2,int param_3,
         int param_4,int param_5,uint param_6,int param_7,uint param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  size_t sVar4;
  size_t cnt;
  EVP_MD *pEVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  byte *pbVar9;
  uint *puVar10;
  uint *puVar11;
  char *__s;
  int in_GS_OFFSET;
  bool bVar12;
  byte *pbVar13;
  size_t local_78;
  uint local_70;
  EVP_MD_CTX local_60;
  EVP_MD_CTX local_48;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2_00 == (byte **)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("salt_p != NULL","passwd.c",0x197,"do_passwd");
  }
  if (param_3_00 == (byte **)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("salt_malloc_p != NULL","passwd.c",0x198,"do_passwd");
  }
  if (param_1_00 == 0) {
    if (param_7 != 0) {
      if (*param_3_00 == (byte *)0x0) {
        pbVar9 = (byte *)CRYPTO_malloc(3,"passwd.c",0x19f);
        *param_3_00 = pbVar9;
        *param_2_00 = pbVar9;
        if (*param_3_00 != (byte *)0x0) goto LAB_08055697;
      }
      else {
        pbVar9 = *param_2_00;
LAB_08055697:
        iVar1 = RAND_bytes(pbVar9,2);
        if (0 < iVar1) {
          **param_2_00 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                         [**param_2_00 & 0x3f];
          (*param_2_00)[1] =
               "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
               [(*param_2_00)[1] & 0x3f];
          (*param_2_00)[2] = 0;
          goto LAB_080556dd;
        }
      }
LAB_08055fe8:
      uVar8 = 0;
      goto LAB_08055f24;
    }
LAB_080556dd:
    if ((param_8 | param_9) != 0) {
      if (*param_3_00 == (byte *)0x0) {
        pbVar9 = (byte *)CRYPTO_malloc(9,"passwd.c",0x1b4);
        *param_3_00 = pbVar9;
        *param_2_00 = pbVar9;
        if (*param_3_00 == (byte *)0x0) {
          uVar8 = 0;
          goto LAB_08055f24;
        }
      }
      else {
        pbVar9 = *param_2_00;
      }
      iVar1 = RAND_bytes(pbVar9,8);
      if (iVar1 < 1) goto LAB_08055fe8;
      **param_2_00 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                     [**param_2_00 & 0x3f];
      (*param_2_00)[1] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[1] & 0x3f];
      (*param_2_00)[2] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[2] & 0x3f];
      (*param_2_00)[3] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[3] & 0x3f];
      (*param_2_00)[4] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[4] & 0x3f];
      (*param_2_00)[5] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[5] & 0x3f];
      (*param_2_00)[6] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[6] & 0x3f];
      (*param_2_00)[7] =
           "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
           [(*param_2_00)[7] & 0x3f];
      (*param_2_00)[8] = 0;
    }
  }
  if (*param_2_00 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("*salt_p != NULL","passwd.c",0x1c2,"do_passwd");
  }
  local_78 = strlen((char *)param_1);
  if (param_6 < local_78) {
    if (param_3 == 0) {
      BIO_printf(bio_err,"Warning: truncating password to %u characters\n",param_6);
    }
    param_1[param_6] = 0;
    local_78 = strlen((char *)param_1);
    if (param_6 < local_78) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(passwd) <= pw_maxlen","passwd.c",0x1cf,"do_passwd");
    }
  }
  if (param_7 == 0) {
    if ((param_8 | param_9) == 0) {
LAB_08055f7a:
                    /* WARNING: Subroutine does not return */
      __assert_fail("hash != NULL","passwd.c",0x1da,"do_passwd");
    }
LAB_080557e9:
    pbVar9 = *param_2_00;
    __s = "1";
    if (param_8 == 0) {
      __s = "apr1";
    }
    out_buf_16055[0] = 0x24;
    out_buf_16055[1] = 0;
    __strncat_chk(out_buf_16055,__s,4,0x29);
    __strcat_chk(out_buf_16055,&DAT_081ed452,0x29);
    __strncat_chk(out_buf_16055,pbVar9,8,0x29);
    puVar11 = (uint *)out_buf_16055;
    do {
      puVar10 = puVar11;
      uVar2 = *puVar10 + 0xfefefeff & ~*puVar10;
      uVar3 = uVar2 & 0x80808080;
      puVar11 = puVar10 + 1;
    } while (uVar3 == 0);
    bVar12 = (uVar2 & 0x8080) == 0;
    if (bVar12) {
      uVar3 = uVar3 >> 0x10;
    }
    if (bVar12) {
      puVar11 = (uint *)((int)puVar10 + 6);
    }
    if (0xe < (int)puVar11 + (-0x82fdda3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(out_buf) <= 6 + 8","passwd.c",0x138,__PRETTY_FUNCTION___16064);
    }
    sVar4 = strlen(__s);
    pcVar6 = out_buf_16055 + sVar4 + 2;
    cnt = strlen(pcVar6);
    if (8 < cnt) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("salt_len <= 8","passwd.c",0x13b,__PRETTY_FUNCTION___16064);
    }
    EVP_MD_CTX_init(&local_60);
    pEVar5 = EVP_md5();
    EVP_DigestInit_ex(&local_60,pEVar5,(ENGINE *)0x0);
    EVP_DigestUpdate(&local_60,param_1,local_78);
    EVP_DigestUpdate(&local_60,&DAT_081ed452,1);
    EVP_DigestUpdate(&local_60,__s,sVar4);
    EVP_DigestUpdate(&local_60,&DAT_081ed452,1);
    EVP_DigestUpdate(&local_60,pcVar6,cnt);
    EVP_MD_CTX_init(&local_48);
    pEVar5 = EVP_md5();
    EVP_DigestInit_ex(&local_48,pEVar5,(ENGINE *)0x0);
    EVP_DigestUpdate(&local_48,param_1,local_78);
    EVP_DigestUpdate(&local_48,pcVar6,cnt);
    EVP_DigestUpdate(&local_48,param_1,local_78);
    EVP_DigestFinal_ex(&local_48,&local_30,(uint *)0x0);
    sVar4 = local_78;
    uVar3 = local_78;
    if (0x10 < local_78) {
      do {
        uVar3 = uVar3 - 0x10;
        EVP_DigestUpdate(&local_60,&local_30,0x10);
      } while (0x10 < uVar3);
      sVar4 = (local_78 - 0x10) - (local_78 - 0x11 & 0xfffffff0);
    }
    EVP_DigestUpdate(&local_60,&local_30,sVar4);
    if (local_78 != 0) {
      local_70 = local_78;
      do {
        pbVar9 = param_1;
        if ((local_70 & 1) != 0) {
          pbVar9 = &DAT_081ed360;
        }
        EVP_DigestUpdate(&local_60,pbVar9,1);
        local_70 = (int)local_70 >> 1;
      } while (local_70 != 0);
    }
    uVar3 = 0;
    EVP_DigestFinal_ex(&local_60,&local_30,(uint *)0x0);
    do {
      pEVar5 = EVP_md5();
      EVP_DigestInit_ex(&local_48,pEVar5,(ENGINE *)0x0);
      pbVar9 = param_1;
      sVar4 = local_78;
      if ((uVar3 & 1) == 0) {
        pbVar9 = &local_30;
        sVar4 = 0x10;
      }
      EVP_DigestUpdate(&local_48,pbVar9,sVar4);
      if (uVar3 != (uVar3 / 3) * 3) {
        EVP_DigestUpdate(&local_48,pcVar6,cnt);
      }
      if (uVar3 % 7 != 0) {
        EVP_DigestUpdate(&local_48,param_1,local_78);
      }
      pbVar9 = param_1;
      sVar4 = local_78;
      if ((uVar3 & 1) != 0) {
        pbVar9 = &local_30;
        sVar4 = 0x10;
      }
      uVar3 = uVar3 + 1;
      EVP_DigestUpdate(&local_48,pbVar9,sVar4);
      EVP_DigestFinal_ex(&local_48,&local_30,(uint *)0x0);
    } while (uVar3 != 1000);
    EVP_MD_CTX_cleanup(&local_48);
    pcVar6 = pcVar6 + cnt;
    puVar11 = (uint *)out_buf_16055;
    do {
      puVar10 = puVar11;
      uVar2 = *puVar10 + 0xfefefeff & ~*puVar10;
      uVar3 = uVar2 & 0x80808080;
      puVar11 = puVar10 + 1;
    } while (uVar3 == 0);
    bVar12 = (uVar2 & 0x8080) == 0;
    if (bVar12) {
      uVar3 = uVar3 >> 0x10;
    }
    if (bVar12) {
      puVar11 = (uint *)((int)puVar10 + 6);
    }
    if (pcVar6 != (char *)((int)puVar11 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)))) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("output == out_buf + strlen(out_buf)","passwd.c",0x178,__PRETTY_FUNCTION___16064
                   );
    }
    *pcVar6 = '$';
    pcVar6[1] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [local_24 & 0x3f];
    pcVar6[2] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [(local_2a & 0xf) << 2 | (uint)(local_24 >> 6)];
    pcVar6[3] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [(local_30 & 3) << 4 | (uint)(local_2a >> 4)];
    pcVar6[4] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [local_30 >> 2];
    pcVar6[5] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [local_23 & 0x3f];
    pcVar6[6] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [(local_29 & 0xf) << 2 | (uint)(local_23 >> 6)];
    pcVar6[7] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [(local_2f & 3) << 4 | (uint)(local_29 >> 4)];
    pcVar6[8] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [local_2f >> 2];
    pcVar6[9] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                [local_22 & 0x3f];
    pcVar6[10] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                 [(local_28 & 0xf) << 2 | (uint)(local_22 >> 6)];
    pcVar6[0xb] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                  [(local_2e & 3) << 4 | (uint)(local_28 >> 4)];
    pcVar6[0xc] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                  [local_2e >> 2];
    pcVar6[0x17] = '\0';
    pcVar6[0xd] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                  [local_21 & 0x3f];
    pcVar6[0xe] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                  [(local_27 & 0xf) << 2 | (uint)(local_21 >> 6)];
    pcVar6[0xf] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                  [(local_2d & 3) << 4 | (uint)(local_27 >> 4)];
    pcVar6[0x10] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [local_2d >> 2];
    pcVar6[0x11] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [local_2b & 0x3f];
    pcVar6[0x12] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [(local_26 & 0xf) << 2 | (uint)(local_2b >> 6)];
    pcVar6[0x13] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [(local_2c & 3) << 4 | (uint)(local_26 >> 4)];
    pcVar6[0x14] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [local_2c >> 2];
    pcVar6[0x15] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [local_25 & 0x3f];
    pcVar6[0x16] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzpasswd.c"
                   [local_25 >> 6];
    puVar11 = (uint *)out_buf_16055;
    do {
      puVar10 = puVar11;
      uVar2 = *puVar10 + 0xfefefeff & ~*puVar10;
      uVar3 = uVar2 & 0x80808080;
      puVar11 = puVar10 + 1;
    } while (uVar3 == 0);
    bVar12 = (uVar2 & 0x8080) == 0;
    if (bVar12) {
      uVar3 = uVar3 >> 0x10;
    }
    if (bVar12) {
      puVar11 = (uint *)((int)puVar10 + 6);
    }
    if (0x28 < (int)puVar11 + (-0x82fdda3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("strlen(out_buf) < sizeof(out_buf)","passwd.c",0x188,__PRETTY_FUNCTION___16064);
    }
    EVP_MD_CTX_cleanup(&local_60);
    puVar7 = out_buf_16055;
  }
  else {
    puVar7 = DES_crypt((char *)param_1,(char *)*param_2_00);
    if ((param_8 | param_9) != 0) {
      local_78 = strlen((char *)param_1);
      goto LAB_080557e9;
    }
    if (puVar7 == (byte *)0x0) goto LAB_08055f7a;
  }
  if (((param_5 == 0) && (pbVar9 = param_1, pbVar13 = puVar7, param_4 != 0)) ||
     ((param_5 != 0 && (pbVar9 = puVar7, pbVar13 = param_1, param_4 != 0)))) {
    BIO_printf(param_2,"%s\t%s\n",pbVar9,pbVar13);
    uVar8 = 1;
  }
  else {
    BIO_printf(param_2,"%s\n",puVar7);
    uVar8 = 1;
  }
LAB_08055f24:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

