
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
do_passwd(int param_1,byte **param_2,byte **param_3,byte *param_4,undefined4 param_5,int param_6,
         int param_7,int param_8,uint param_9,uint param_10,uint param_11,int param_12)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  undefined uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  undefined *puVar17;
  undefined *puVar18;
  undefined8 *puVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  uint uVar24;
  int iVar25;
  undefined *puVar26;
  byte bVar27;
  byte *pbVar28;
  char *pcVar29;
  undefined1 *puVar30;
  undefined8 *puVar31;
  int iVar32;
  int iVar33;
  char *pcVar34;
  char *unaff_s5;
  bool bVar35;
  undefined *unaff_s6;
  uint unaff_s7;
  undefined4 uVar36;
  code *pcVar37;
  undefined4 uStack_2138;
  undefined4 uStack_2134;
  undefined4 uStack_2130;
  undefined4 uStack_212c;
  int iStack_2124;
  int iStack_2118;
  undefined8 *puStack_2104;
  int iStack_20e4;
  int iStack_20e0;
  undefined auStack_20dc [8192];
  int iStack_dc;
  uint uStack_d8;
  byte **ppbStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  byte **ppbStack_c8;
  char *pcStack_c4;
  undefined *puStack_c0;
  uint uStack_bc;
  byte *pbStack_b8;
  code *pcStack_b4;
  undefined *local_a0;
  undefined1 *local_98;
  uint local_94;
  undefined1 *local_90;
  undefined *local_8c;
  int *local_88;
  undefined4 local_84;
  undefined1 *local_80;
  uint local_7c;
  uint local_78;
  code *local_74;
  undefined auStack_6c [24];
  undefined auStack_54 [24];
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
  byte local_2d;
  int local_2c;
  
  local_88 = (int *)PTR___stack_chk_guard_006aabf0;
  local_a0 = &_gp;
  local_84 = param_5;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 == (byte **)0x0) {
    uVar23 = (*(code *)PTR___assert_fail_006aaa4c)("salt_p != NULL","passwd.c",0x1a7,"do_passwd");
    return uVar23;
  }
  if (param_3 == (byte **)0x0) {
    uVar23 = (*(code *)PTR___assert_fail_006aaa4c)
                       ("salt_malloc_p != NULL","passwd.c",0x1a8,"do_passwd");
    return uVar23;
  }
  if (param_1 == 0) {
    if (param_10 == 0) {
LAB_0042cef4:
      if ((param_11 != 0) || (param_12 != 0)) {
        if (*param_3 == (byte *)0x0) {
          pcVar29 = "passwd.c";
          pbVar28 = (byte *)(**(code **)(local_a0 + -0x7dd8))(9,"passwd.c",0x1c9);
          *param_3 = pbVar28;
          *param_2 = pbVar28;
          if (*param_3 == (byte *)0x0) goto LAB_0042d8a0;
          pcVar37 = *(code **)(local_a0 + -0x787c);
        }
        else {
          pbVar28 = *param_2;
          pcVar37 = *(code **)(local_a0 + -0x787c);
        }
        pcVar29 = (char *)0x8;
        iVar20 = (*pcVar37)(pbVar28);
        if (iVar20 < 0) goto LAB_0042d8a0;
        **param_2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                    [**param_2 & 0x3f];
        (*param_2)[1] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[1] & 0x3f];
        (*param_2)[2] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[2] & 0x3f];
        (*param_2)[3] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[3] & 0x3f];
        (*param_2)[4] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[4] & 0x3f];
        (*param_2)[5] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[5] & 0x3f];
        (*param_2)[6] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[6] & 0x3f];
        (*param_2)[7] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[7] & 0x3f];
        (*param_2)[8] = 0;
      }
      goto LAB_0042cff8;
    }
    if (*param_3 == (byte *)0x0) {
      pcVar29 = "passwd.c";
      pbVar28 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"passwd.c",0x1b2);
      *param_3 = pbVar28;
      *param_2 = pbVar28;
      pcVar37 = *(code **)(local_a0 + -0x787c);
      if (*param_3 != (byte *)0x0) goto LAB_0042cea4;
    }
    else {
      pbVar28 = *param_2;
      pcVar37 = (code *)PTR_RAND_pseudo_bytes_006a8664;
LAB_0042cea4:
      pcVar29 = (char *)0x2;
      iVar20 = (*pcVar37)(pbVar28);
      if (-1 < iVar20) {
        **param_2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                    [**param_2 & 0x3f];
        (*param_2)[1] =
             "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
             [(*param_2)[1] & 0x3f];
        (*param_2)[2] = 0;
        goto LAB_0042cef4;
      }
    }
LAB_0042d8a0:
    uVar23 = 0;
  }
  else {
LAB_0042cff8:
    if (*param_2 == (byte *)0x0) {
      uVar23 = (**(code **)(local_a0 + -0x5494))("*salt_p != NULL","passwd.c",0x1d7,"do_passwd");
      return uVar23;
    }
    uVar21 = (**(code **)(local_a0 + -0x53b0))(param_4);
    if (param_9 < uVar21) {
      if (param_6 == 0) {
        (**(code **)(local_a0 + -0x7fa8))
                  (**(undefined4 **)(local_a0 + -0x7fa4),
                   "Warning: truncating password to %u characters\n",param_9);
      }
      pcVar37 = *(code **)(local_a0 + -0x53b0);
      param_4[param_9] = 0;
      uVar21 = (*pcVar37)(param_4);
      if (param_9 < uVar21) {
        uVar23 = (**(code **)(local_a0 + -0x5494))
                           ("strlen(passwd) <= pw_maxlen","passwd.c",0x1e1,"do_passwd");
        return uVar23;
      }
    }
    if (param_10 == 0) {
      puVar30 = (undefined1 *)0x0;
      if (param_11 == 0) goto LAB_0042d05c;
LAB_0042d790:
      pcVar29 = "1";
LAB_0042d068:
      pbVar28 = *param_2;
      uVar21 = (**(code **)(local_a0 + -0x53b0))(param_4);
      local_80 = &_ITM_registerTMCloneTable;
      local_90 = out_buf_16018;
      out_buf_16018[1] = 0;
      out_buf_16018[0] = 0x24;
      (**(code **)(local_a0 + -0x545c))(out_buf_16018,pcVar29,4,0x29);
      (**(code **)(local_a0 + -0x52b4))(out_buf_16018,&DAT_006355f4,0x29);
      (**(code **)(local_a0 + -0x545c))(out_buf_16018,pbVar28,8,0x29);
      uVar22 = (**(code **)(local_a0 + -0x53b0))(out_buf_16018);
      if (0xe < uVar22) {
        uVar23 = (**(code **)(local_a0 + -0x5494))
                           ("strlen(out_buf) <= 6 + 8","passwd.c",0x147,__PRETTY_FUNCTION___16027);
        return uVar23;
      }
      iVar20 = (**(code **)(local_a0 + -0x53b0))(pcVar29);
      local_98 = local_90 + iVar20 + 2;
      local_94 = (**(code **)(local_a0 + -0x53b0))(local_98);
      if (8 < local_94) {
        uVar23 = (**(code **)(local_a0 + -0x5494))
                           ("salt_len <= 8","passwd.c",0x14a,__PRETTY_FUNCTION___16027);
        return uVar23;
      }
      local_8c = auStack_6c;
      (**(code **)(local_a0 + -0x7fc4))(auStack_6c);
      uVar23 = (**(code **)(local_a0 + -0x7d18))();
      (**(code **)(local_a0 + -0x7870))(auStack_6c,uVar23,0);
      (**(code **)(local_a0 + -0x786c))(auStack_6c,param_4,uVar21);
      (**(code **)(local_a0 + -0x786c))(auStack_6c,&DAT_006355f4,1);
      (**(code **)(local_a0 + -0x786c))(auStack_6c,pcVar29,iVar20);
      (**(code **)(local_a0 + -0x786c))(auStack_6c,&DAT_006355f4,1);
      uVar22 = local_94;
      puVar30 = local_98;
      (**(code **)(local_a0 + -0x786c))(auStack_6c,local_98,local_94);
      (**(code **)(local_a0 + -0x7fc4))(auStack_54);
      uVar23 = (**(code **)(local_a0 + -0x7d18))();
      (**(code **)(local_a0 + -0x7870))(auStack_54,uVar23,0);
      (**(code **)(local_a0 + -0x786c))(auStack_54,param_4,uVar21);
      (**(code **)(local_a0 + -0x786c))(auStack_54,puVar30,uVar22);
      (**(code **)(local_a0 + -0x786c))(auStack_54,param_4,uVar21);
      (**(code **)(local_a0 + -0x7868))(auStack_54,&local_3c,0);
      uVar22 = uVar21;
      if (0x10 < uVar21) {
        do {
          uVar22 = uVar22 - 0x10;
          (**(code **)(local_a0 + -0x786c))(auStack_6c,&local_3c,0x10);
        } while (0x10 < uVar22);
        uVar22 = (uVar21 - 0x10) - (uVar21 - 0x11 & 0xfffffff0);
      }
      (**(code **)(local_a0 + -0x786c))(local_8c,&local_3c,uVar22);
      puVar17 = local_8c;
      uVar22 = uVar21;
      while (uVar22 != 0) {
        while( true ) {
          uVar24 = uVar22 & 1;
          uVar22 = (int)uVar22 >> 1;
          if (uVar24 != 0) break;
          (**(code **)(local_a0 + -0x786c))(puVar17,param_4,1);
          if (uVar22 == 0) goto LAB_0042d364;
        }
        (**(code **)(local_a0 + -0x786c))(puVar17,&DAT_006354c0,1);
      }
LAB_0042d364:
      (**(code **)(local_a0 + -0x7868))(local_8c,&local_3c,0);
      uVar22 = 0;
      do {
        uVar23 = (**(code **)(local_a0 + -0x7d18))();
        (**(code **)(local_a0 + -0x7870))(auStack_54,uVar23,0);
        pbVar28 = param_4;
        uVar24 = uVar21;
        if ((uVar22 & 1) == 0) {
          pbVar28 = &local_3c;
          uVar24 = 0x10;
        }
        (**(code **)(local_a0 + -0x786c))(auStack_54,pbVar28,uVar24);
        if (uVar22 != ((uint)((ulonglong)uVar22 * 0xaaaaaaab >> 0x20) & 0xfffffffe) + uVar22 / 3) {
          (**(code **)(local_a0 + -0x786c))(auStack_54,local_98,local_94);
        }
        if (uVar22 != (uVar22 / 7) * 7) {
          (**(code **)(local_a0 + -0x786c))(auStack_54,param_4,uVar21);
        }
        pbVar28 = param_4;
        uVar24 = uVar21;
        if ((uVar22 & 1) != 0) {
          pbVar28 = &local_3c;
          uVar24 = 0x10;
        }
        uVar22 = uVar22 + 1;
        (**(code **)(local_a0 + -0x786c))(auStack_54,pbVar28,uVar24);
        (**(code **)(local_a0 + -0x7868))(auStack_54,&local_3c,0);
      } while (uVar22 != 1000);
      unaff_s6 = local_98 + local_94;
      (**(code **)(local_a0 + -0x7fac))(auStack_54);
      iVar20 = (**(code **)(local_a0 + -0x53b0))(local_80 + -0x4e40);
      if (unaff_s6 != local_90 + iVar20) {
        uVar23 = (**(code **)(local_a0 + -0x5494))
                           ("output == out_buf + strlen(out_buf)","passwd.c",0x187,
                            __PRETTY_FUNCTION___16027);
        return uVar23;
      }
      local_74 = *(code **)(local_a0 + -0x53b0);
      local_98 = (undefined1 *)((local_3b & 3) << 4);
      local_94 = (local_34 & 0xf) << 2;
      local_80 = (undefined1 *)((local_3a & 3) << 4);
      local_78 = (local_39 & 3) << 4;
      local_7c = (local_33 & 0xf) << 2;
      cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_3c >> 2];
      unaff_s6[3] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                    [(local_3c & 3) << 4 | (uint)(local_36 >> 4)];
      unaff_s6[4] = cVar1;
      cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [(local_36 & 0xf) << 2 | (uint)(local_30 >> 6)];
      cVar2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_2f & 0x3f];
      cVar3 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [(local_35 & 0xf) << 2 | (uint)(local_2f >> 6)];
      cVar4 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [(uint)local_98 | (uint)(local_35 >> 4)];
      unaff_s6[1] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                    [local_30 & 0x3f];
      unaff_s6[2] = cVar1;
      unaff_s6[5] = cVar2;
      bVar27 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
               [(uint)local_80 | (uint)(local_34 >> 4)];
      param_9 = (uint)bVar27;
      bVar5 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_2d & 0x3f];
      param_2 = (byte **)(uint)bVar5;
      bVar6 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [local_78 | local_33 >> 4];
      param_10 = (uint)bVar6;
      bVar7 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_39 >> 2];
      param_11 = (uint)bVar7;
      cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_3b >> 2];
      cVar2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_2e & 0x3f];
      cVar8 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [local_94 | local_2e >> 6];
      cVar9 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_3a >> 2];
      cVar10 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
               [local_7c | local_2d >> 6];
      unaff_s6[6] = cVar3;
      unaff_s6[7] = cVar4;
      unaff_s6[9] = cVar2;
      unaff_s6[0xc] = cVar9;
      unaff_s6[8] = cVar1;
      unaff_s6[10] = cVar8;
      unaff_s6[0xb] = bVar27;
      unaff_s6[0xd] = bVar5;
      unaff_s7 = local_31 & 0x3f;
      unaff_s6[0xe] = cVar10;
      unaff_s6[0xf] = bVar6;
      unaff_s6[0x10] = bVar7;
      unaff_s6[0x17] = 0;
      param_3 = (byte **)("./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" +
                         ((local_38 & 3) << 4 | (uint)(local_32 >> 4)));
      cVar1 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
              [(local_32 & 0xf) << 2 | (uint)(local_37 >> 6)];
      unaff_s5 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" +
                 (local_38 >> 2);
      cVar2 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_37 & 0x3f];
      cVar3 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[unaff_s7];
      uVar11 = *(undefined *)param_3;
      cVar4 = *unaff_s5;
      cVar8 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[local_31 >> 6];
      *unaff_s6 = 0x24;
      unaff_s6[0x11] = cVar2;
      unaff_s6[0x12] = cVar1;
      unaff_s6[0x13] = uVar11;
      unaff_s6[0x14] = cVar4;
      unaff_s6[0x15] = cVar3;
      unaff_s6[0x16] = cVar8;
      uVar21 = (*local_74)(local_90);
      if (0x28 < uVar21) {
        uVar23 = (**(code **)(local_a0 + -0x5494))
                           ("strlen(out_buf) < sizeof(out_buf)","passwd.c",0x198,
                            __PRETTY_FUNCTION___16027);
        return uVar23;
      }
      (**(code **)(local_a0 + -0x7fac))(local_8c);
      puVar30 = local_90;
    }
    else {
      puVar30 = (undefined1 *)(**(code **)(local_a0 + -0x7874))(param_4,*param_2);
      if (param_11 != 0) goto LAB_0042d790;
LAB_0042d05c:
      param_9 = 0x630000;
      if (param_12 != 0) {
        pcVar29 = "apr1";
        goto LAB_0042d068;
      }
      if (puVar30 == (undefined1 *)0x0) {
        uVar23 = (**(code **)(local_a0 + -0x5494))("hash != NULL","passwd.c",0x1ec,"do_passwd");
        return uVar23;
      }
    }
    if (param_7 == 0) {
      pcVar29 = "%s\n";
      (**(code **)(local_a0 + -0x7fa8))(local_84);
      uVar23 = 1;
    }
    else if (param_8 == 0) {
      pcVar29 = "%s\t%s\n";
      (**(code **)(local_a0 + -0x7fa8))(local_84,&DAT_00635650,param_4,puVar30);
      uVar23 = 1;
    }
    else {
      pcVar29 = "%s\t%s\n";
      (**(code **)(local_a0 + -0x7fa8))(local_84,&DAT_00635650,puVar30,param_4);
      uVar23 = 1;
    }
  }
  if (local_2c == *local_88) {
    return uVar23;
  }
  pcStack_b4 = passwd_main;
  (**(code **)(local_a0 + -0x5328))();
  puVar18 = PTR___stack_chk_guard_006aabf0;
  puVar17 = PTR_bio_err_006a7f3c;
  iStack_20e4 = 0;
  iStack_20e0 = 0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_d8 = param_9;
  ppbStack_d4 = param_2;
  uStack_d0 = param_10;
  uStack_cc = param_11;
  ppbStack_c8 = param_3;
  pcStack_c4 = unaff_s5;
  puStack_c0 = unaff_s6;
  uStack_bc = unaff_s7;
  pbStack_b8 = param_4;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar20 = *(int *)puVar17;
  if (iVar20 == 0) {
    uVar23 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar20 = (*(code *)PTR_BIO_new_006a7fa4)(uVar23);
    *(int *)puVar17 = iVar20;
    if (iVar20 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar20,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar20 = *(int *)puVar17;
    }
  }
  iVar20 = (*(code *)PTR_load_config_006a7f64)(iVar20,0);
  if (iVar20 == 0) {
LAB_0042dc7c:
    iVar20 = 0;
LAB_0042dc80:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
joined_r0x0042def0:
    if (iStack_20e0 == 0) {
      uVar23 = 1;
    }
    else {
      iVar32 = 0;
LAB_0042dc9c:
      iVar33 = 0;
      uVar23 = 1;
LAB_0042dca8:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
LAB_0042dcb4:
      if (iVar33 != 0) {
LAB_0042dcc0:
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar33);
      }
LAB_0042dccc:
      if (iVar32 != 0) goto LAB_0042dcd4;
    }
  }
  else {
    uVar23 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar20 = (*(code *)PTR_BIO_new_006a7fa4)(uVar23);
    if (iVar20 == 0) goto LAB_0042dc7c;
    puVar31 = (undefined8 *)(pcVar29 + 4);
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar20,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
    pcVar34 = *(char **)(pcVar29 + 4);
    if (pcVar34 == (char *)0x0) {
      bVar27 = 1;
      bVar15 = false;
      bVar35 = true;
      bVar14 = false;
      iStack_2118 = 0;
      bVar13 = false;
      cVar2 = '\0';
      uStack_2130 = 0;
      uStack_212c = 0;
      iStack_2124 = 0;
      puStack_2104 = (undefined8 *)0x0;
      uStack_2134 = 0;
      cVar1 = '\0';
    }
    else {
      bVar16 = false;
      cVar2 = '\0';
      cVar1 = '\0';
      uStack_212c = 0;
      uStack_2130 = 0;
      uStack_2134 = 0;
      iStack_2124 = 0;
      bVar12 = false;
      puStack_2104 = (undefined8 *)0x0;
      bVar15 = false;
      bVar14 = false;
      iStack_2118 = 0;
      bVar35 = false;
      iVar32 = 0;
      iVar33 = 1;
      do {
        while (iVar25 = (*(code *)PTR_strcmp_006aac20)(pcVar34,&DAT_00635658),
              puVar19 = puStack_2104, iVar25 != 0) {
          cVar3 = *pcVar34;
          if (((cVar3 == '-') && (pcVar34[1] == '1')) && (pcVar34[2] == '\0')) {
            cVar1 = '\x01';
            bVar13 = false;
          }
          else {
            iVar25 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-apr1");
            if (iVar25 == 0) {
              bVar16 = true;
              cVar2 = '\x01';
              bVar13 = false;
            }
            else {
              iVar25 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-salt");
              if (iVar25 == 0) {
                if ((*(int *)(pcVar29 + (iVar33 + 1) * 4) == 0) || (iStack_20e4 != 0)) {
LAB_0042dd98:
                  bVar13 = true;
                  puVar19 = puStack_2104;
                  goto joined_r0x0042dd9c;
                }
                iVar33 = iVar32 + 2;
                iStack_2124 = 1;
                iStack_20e4 = *(int *)(pcVar29 + iVar33 * 4);
                bVar13 = false;
              }
              else {
                bVar13 = bVar12;
                if (((cVar3 == '-') && (pcVar34[1] == 'i')) &&
                   ((pcVar34[2] == 'n' && (pcVar34[3] == '\0')))) {
                  if ((*(int *)(pcVar29 + (iVar33 + 1) * 4) == 0) || (bVar12)) goto LAB_0042dd98;
                  iVar33 = iVar32 + 2;
                  iStack_2118 = *(int *)(pcVar29 + iVar33 * 4);
                  bVar12 = true;
                }
                else {
                  iVar32 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-stdin");
                  if (iVar32 == 0) {
                    if (bVar12) goto LAB_0042dd98;
                    bVar14 = true;
                    bVar12 = true;
                  }
                  else {
                    iVar32 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-noverify");
                    if (iVar32 == 0) {
                      bVar13 = false;
                      bVar15 = true;
                    }
                    else {
                      iVar32 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-quiet");
                      if (iVar32 == 0) {
                        uStack_2134 = 1;
                        bVar13 = false;
                      }
                      else {
                        iVar32 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-table");
                        if (iVar32 == 0) {
                          uStack_2130 = 1;
                          bVar13 = false;
                        }
                        else {
                          iVar32 = (*(code *)PTR_strcmp_006aac20)(pcVar34,"-reverse");
                          if (iVar32 != 0) {
                            if ((cVar3 == '-') || (bVar13 = false, puVar19 = puVar31, bVar12))
                            goto LAB_0042dd98;
                            goto joined_r0x0042dd9c;
                          }
                          uStack_212c = 1;
                          bVar13 = false;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar31 = (undefined8 *)(pcVar29 + (iVar33 + 1) * 4);
          pcVar34 = *(char **)puVar31;
          iVar32 = iVar33;
          iVar33 = iVar33 + 1;
          if (pcVar34 == (char *)0x0) goto joined_r0x0042dd9c;
        }
        puVar31 = (undefined8 *)(pcVar29 + (iVar33 + 1) * 4);
        bVar35 = true;
        pcVar34 = *(char **)puVar31;
        bVar13 = false;
        iVar32 = iVar33;
        iVar33 = iVar33 + 1;
      } while (pcVar34 != (char *)0x0);
joined_r0x0042dd9c:
      puStack_2104 = puVar19;
      if (bVar35 == false) {
        if (cVar1 == '\0') {
          cVar1 = '\0';
          bVar35 = !bVar16;
          bVar27 = bVar35 + cVar2;
        }
        else {
          bVar27 = cVar2 + 1;
          cVar1 = '\x01';
        }
      }
      else {
        bVar35 = true;
        bVar27 = cVar1 + '\x01' + cVar2;
      }
    }
    if ((1 < bVar27) || (bVar13)) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"Usage: passwd [options] [passwords]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar17,"where options are\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,
                 "-crypt             standard Unix password algorithm (default)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-1                 MD5-based password algorithm\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,
                 "-apr1              MD5-based password algorithm, Apache variant\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-salt string       use provided salt\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-in file           read passwords from file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-stdin             read passwords from stdin\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,
                 "-noverify          never verify when reading password from terminal\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar17,"-quiet             no warnings\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-table             format output as table\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar17,"-reverse           switch table columns\n");
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
      goto joined_r0x0042def0;
    }
    if (iStack_2118 == 0) {
      if (bVar14) {
        uVar23 = (*(code *)PTR_BIO_s_file_006a7fa0)();
        iVar32 = (*(code *)PTR_BIO_new_006a7fa4)(uVar23);
        if (iVar32 == 0) goto LAB_0042dc80;
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar32,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
      }
      else {
        iVar32 = 0;
      }
LAB_0042e010:
      if (bVar35 == false) {
        if (cVar1 == '\0') {
          uStack_2138 = 1;
          uVar23 = 0x100;
          if (cVar2 != '\0') {
            uStack_2138 = 0x101;
          }
          uVar36 = 2;
          if (cVar2 == '\0') {
            uVar23 = 0;
          }
          else {
            uVar36 = 0x102;
          }
        }
        else {
          uVar36 = 0x102;
          uVar23 = 0x100;
          uStack_2138 = 0x101;
        }
      }
      else {
        uVar36 = 10;
        uVar23 = 8;
        uStack_2138 = 9;
      }
      if (puStack_2104 != (undefined8 *)0x0) {
        if (iVar32 != 0) {
          uVar23 = (*(code *)PTR___assert_fail_006aaa4c)
                             ("passwd != NULL","passwd.c",0x100,"passwd_main");
          return uVar23;
        }
        iVar33 = 0;
        if (*(int *)puStack_2104 == 0) {
          uVar23 = (*(code *)PTR___assert_fail_006aaa4c)
                             ("*passwds != NULL","passwd.c",0xf0,"passwd_main");
          return uVar23;
        }
LAB_0042e24c:
        do {
          puVar31 = (undefined8 *)((int)puStack_2104 + 4);
          iVar32 = do_passwd(iStack_2124,&iStack_20e4,&iStack_20e0,*(undefined4 *)puStack_2104,
                             iVar20,uStack_2134,uStack_2130,uStack_212c,uVar23,bVar35,cVar1,cVar2);
          if (iVar32 == 0) {
            uVar23 = 1;
            goto LAB_0042e2cc;
          }
          puStack_2104 = puVar31;
        } while (*(int *)puVar31 != 0);
        uVar23 = 0;
LAB_0042e2cc:
        iVar32 = 0;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
        if (iStack_20e0 != 0) goto LAB_0042dca8;
        goto LAB_0042dcb4;
      }
      iVar33 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar36,"passwd.c",0xdc);
      if (iVar33 != 0) {
        if (iVar32 == 0) {
          iVar25 = (*(code *)PTR_EVP_read_pw_string_006a8388)
                             (iVar33,uVar36,"Password: ",iStack_2124 == 0 && !bVar15);
          if (iVar25 == 0) {
            puStack_2104 = &passwds_static_16002;
            passwds_static_16002._0_4_ = iVar33;
            goto LAB_0042e24c;
          }
        }
        else {
          do {
            while( true ) {
              iVar25 = (*(code *)PTR_BIO_gets_006a85d0)(iVar32,iVar33,uStack_2138);
              if (iVar25 < 1) {
                uVar23 = 0;
                goto LAB_0042e3cc;
              }
              puVar26 = (undefined *)(*(code *)PTR_strchr_006aab34)(iVar33,10);
              if (puVar26 != (undefined *)0x0) break;
              do {
                iVar25 = (*(code *)PTR_BIO_gets_006a85d0)(iVar32,auStack_20dc,0x2000);
                if (iVar25 < 1) {
                  iVar25 = do_passwd(iStack_2124,&iStack_20e4,&iStack_20e0,iVar33,iVar20,uStack_2134
                                     ,uStack_2130,uStack_212c,uVar23,bVar35,cVar1,cVar2);
                  if (iVar25 == 0) goto LAB_0042e4ec;
                  uVar23 = 0;
                  goto LAB_0042e474;
                }
                iVar25 = (*(code *)PTR_strchr_006aab34)(auStack_20dc,10);
              } while (iVar25 == 0);
              iVar25 = do_passwd(iStack_2124,&iStack_20e4,&iStack_20e0,iVar33,iVar20,uStack_2134,
                                 uStack_2130,uStack_212c,uVar23,bVar35,cVar1,cVar2);
              if (iVar25 == 0) {
LAB_0042e4ec:
                uVar23 = 1;
LAB_0042e474:
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
                goto joined_r0x0042e3dc;
              }
            }
            *puVar26 = 0;
            iVar25 = do_passwd(iStack_2124,&iStack_20e4,&iStack_20e0,iVar33,iVar20,uStack_2134,
                               uStack_2130,uStack_212c,uVar23,bVar35,cVar1,cVar2);
          } while (iVar25 != 0);
        }
        uVar23 = 1;
LAB_0042e3cc:
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
joined_r0x0042e3dc:
        if (iStack_20e0 != 0) goto LAB_0042dca8;
        goto LAB_0042dcc0;
      }
      uVar23 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
      if (iStack_20e0 != 0) goto LAB_0042dca8;
      goto LAB_0042dccc;
    }
    uVar23 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar32 = (*(code *)PTR_BIO_new_006a7fa4)(uVar23);
    if (iVar32 == 0) goto LAB_0042dc80;
    if (bVar14) goto LAB_0042e5cc;
    iVar33 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar32,0x6c,3,iStack_2118);
    if (0 < iVar33) goto LAB_0042e010;
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar17);
    if (iStack_20e0 != 0) goto LAB_0042dc9c;
    uVar23 = 1;
LAB_0042dcd4:
    (*(code *)PTR_BIO_free_006a7f70)(iVar32);
  }
  if (iVar20 != 0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar20);
  }
  if (iStack_dc == *(int *)puVar18) {
    return uVar23;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042e5cc:
  uVar23 = (*(code *)PTR___assert_fail_006aaa4c)("in_stdin == 0","passwd.c",0xc6,"passwd_main");
  return uVar23;
}

