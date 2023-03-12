
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SMIME_text(BIO *in,BIO *out)

{
  undefined *puVar1;
  BIO *pBVar2;
  int iVar3;
  uint uVar4;
  BIO **ppBVar5;
  uint uVar6;
  stack_st_void *psVar7;
  BIO **ppBVar8;
  stack_st_OPENSSL_BLOCK *psVar9;
  BIO_METHOD *pBVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  BIO *pBVar14;
  BIO_METHOD **pp;
  undefined4 *puVar15;
  int *piVar16;
  BIO *pBVar17;
  int **ppiVar18;
  int **ppiVar19;
  undefined4 uVar20;
  char *in_a3;
  char *pcVar21;
  BIO *pBVar22;
  BIO *unaff_s0;
  BIO *pBVar23;
  int *piVar24;
  BIO *unaff_s4;
  BIO *unaff_s5;
  BIO *pBVar25;
  BIO *unaff_s6;
  bio_st *unaff_s7;
  code *pcVar26;
  BIO *unaff_s8;
  int iStack_13f0;
  int iStack_13ec;
  undefined *puStack_13e4;
  BIO *pBStack_13e0;
  undefined *puStack_13dc;
  uchar **ppuStack_13d8;
  char *pcStack_13d4;
  char *pcStack_13d0;
  code *pcStack_13cc;
  undefined4 uStack_13b8;
  undefined *puStack_13b0;
  int iStack_13a4;
  undefined4 uStack_13a0;
  int iStack_139c;
  BIO_METHOD *pBStack_1398;
  code *pcStack_1394;
  BIO_METHOD *pBStack_1370;
  undefined4 *puStack_136c;
  undefined *puStack_1364;
  BIO *pBStack_1360;
  int **ppiStack_135c;
  BIO *pBStack_1358;
  BIO *pBStack_1354;
  BIO *pBStack_1350;
  BIO *pBStack_134c;
  bio_st *pbStack_1348;
  code *pcStack_1344;
  uchar *puStack_1310;
  stack_st_OPENSSL_BLOCK *psStack_130c;
  BIO **ppBStack_1308;
  undefined4 uStack_1304;
  BIO *pBStack_12f0;
  undefined4 uStack_12ec;
  BIO **ppBStack_12e8;
  undefined *puStack_12e0;
  BIO *pBStack_12d4;
  BIO **ppBStack_12d0;
  BIO *pBStack_12cc;
  uchar **ppuStack_12c8;
  BIO *pBStack_12c4;
  BIO **ppBStack_12c0;
  char *pcStack_12bc;
  BIO *pBStack_12b8;
  undefined auStack_12b4 [8];
  undefined auStack_12ac [4];
  BIO *pBStack_12a8;
  undefined auStack_12a4 [8];
  undefined auStack_129c [8];
  _func_603 *p_Stack_1294;
  BIO *pBStack_1290;
  bio_st *pbStack_128c;
  bio_st *pbStack_1288;
  BIO *pBStack_1284;
  ulong uStack_1280;
  undefined auStack_127c [48];
  ulong uStack_124c;
  BIO *pBStack_1248;
  stack_st_void *psStack_1244;
  BIO *pBStack_1240;
  BIO *pBStack_123c;
  BIO *pBStack_1238;
  undefined *puStack_1234;
  BIO *pBStack_1230;
  bio_st *pbStack_122c;
  uchar *puStack_1224;
  BIO *pBStack_1220;
  BIO **ppBStack_121c;
  BIO *pBStack_1218;
  char *pcStack_1214;
  undefined *puStack_1210;
  BIO *pBStack_120c;
  BIO *pBStack_1208;
  bio_st *pbStack_1204;
  BIO *pBStack_1200;
  code *pcStack_11fc;
  BIO *pBStack_11e8;
  undefined *puStack_11e0;
  BIO_METHOD *pBStack_11d8;
  int **ppiStack_11d4;
  BIO *pBStack_11d0;
  BIO **ppBStack_11cc;
  undefined *puStack_11c8;
  BIO *pBStack_11c4;
  BIO *pBStack_11c0;
  BIO *pBStack_11bc;
  BIO *pBStack_11b8;
  code *pcStack_11b4;
  BIO *pBStack_11a0;
  undefined *puStack_1198;
  BIO *pBStack_118c;
  BIO *pBStack_1184;
  undefined auStack_1180 [4];
  _func_603 *p_Stack_117c;
  BIO BStack_1178;
  undefined *puStack_1138;
  BIO *pBStack_112c;
  BIO *pBStack_1128;
  BIO *pBStack_1124;
  undefined4 *puStack_1120;
  bio_st **ppbStack_111c;
  BIO *pBStack_1118;
  undefined *puStack_1114;
  int iStack_1110;
  char *pcStack_110c;
  BIO *pBStack_1108;
  undefined auStack_1104 [8];
  undefined auStack_10fc [4];
  BIO *pBStack_10f8;
  undefined auStack_10f4 [8];
  undefined auStack_10ec [8];
  _func_603 *p_Stack_10e4;
  bio_st *pbStack_10e0;
  bio_st *pbStack_10dc;
  undefined auStack_10d8 [16];
  bio_st *pbStack_10c8;
  bio_st *pbStack_10c4;
  uint uStack_10c0;
  BIO *pBStack_10bc;
  BIO *pBStack_10b8;
  BIO *pBStack_10b4;
  bio_st *pbStack_10b0;
  BIO *pBStack_10ac;
  BIO *pBStack_10a8;
  undefined auStack_10a0 [8];
  bio_st *pbStack_1098;
  uint uStack_1094;
  BIO *pBStack_1090;
  BIO *pBStack_108c;
  BIO *pBStack_1088;
  undefined *puStack_1084;
  BIO *pBStack_1080;
  bio_st *pbStack_107c;
  BIO **ppBStack_1074;
  BIO *pBStack_1070;
  BIO *pBStack_106c;
  BIO *pBStack_1068;
  undefined *puStack_1064;
  BIO *pBStack_1060;
  BIO *local_1038;
  int iStack_1034;
  char *local_1028 [3];
  BIO aBStack_101c [64];
  BIO **local_1c;
  
  BStack_1178.flags = (int)PTR___stack_chk_guard_006a9ae8;
  local_1c = *(BIO ***)PTR___stack_chk_guard_006a9ae8;
  pBVar2 = (BIO *)mime_parse_hdr();
  if (pBVar2 == (BIO *)0x0) {
    pBVar17 = (BIO *)0xcf;
    in_a3 = "asn_mime.c";
    local_1038 = (BIO *)0x238;
    pcStack_1214 = (char *)0xd5;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    uVar4 = 0;
  }
  else {
    local_1028[0] = "content-type";
    iVar3 = (*(code *)PTR_sk_find_006a8044)(pBVar2,local_1028);
    if (((iVar3 < 0) ||
        (unaff_s4 = (BIO *)(*(code *)PTR_sk_value_006a6e24)(pBVar2,iVar3), unaff_s4 == (BIO *)0x0))
       || (unaff_s4->callback == (_func_603 *)0x0)) {
      pBVar17 = (BIO *)0xce;
      in_a3 = "asn_mime.c";
      local_1038 = (BIO *)0x23c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd5);
    }
    else {
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(unaff_s4->callback,"text/plain");
      if (iVar3 == 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(pBVar2,mime_hdr_free);
        while( true ) {
          pBVar17 = (BIO *)0x1000;
          pcStack_1214 = (char *)aBStack_101c;
          iVar3 = (*(code *)PTR_BIO_read_006a74c0)(in);
          if (iVar3 < 1) break;
          (*(code *)PTR_BIO_write_006a6e14)(out,aBStack_101c,iVar3);
        }
        uVar4 = (uint)(iVar3 == 0);
        unaff_s0 = aBStack_101c;
        goto LAB_0060de50;
      }
      in_a3 = "asn_mime.c";
      local_1038 = (BIO *)0x241;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd5,0xcd);
      pBVar17 = (BIO *)unaff_s4->callback;
      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"type: ");
    }
    pcVar26 = mime_hdr_free;
    (*(code *)PTR_sk_pop_free_006a7058)(pBVar2);
    uVar4 = 0;
    pcStack_1214 = (char *)pcVar26;
    unaff_s0 = pBVar2;
  }
LAB_0060de50:
  if (local_1c == *(BIO ***)BStack_1178.flags) {
    return uVar4;
  }
  BStack_1178.shutdown = (int)local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppbStack_111c = (bio_st **)&_gp;
  puStack_1120 = (undefined4 *)PTR___stack_chk_guard_006a9ae8;
  puStack_1064 = (undefined *)BStack_1178.flags;
  puStack_1138 = &_gp;
  ppBStack_1074 = *(BIO ***)PTR___stack_chk_guard_006a9ae8;
  pBVar2 = (BIO *)(uint)(iStack_1034 < 0x15);
  pBStack_1220 = pBVar17;
  pBStack_11c0 = (BIO *)in_a3;
  pBStack_1124 = (BIO *)pcStack_1214;
  pBStack_1070 = unaff_s0;
  pBStack_106c = in;
  pBStack_1068 = out;
  pBStack_1060 = unaff_s4;
  if (pBVar2 == (BIO *)0x0) {
    __gp = 0xc5;
  }
  else if ((((BIO **)BStack_1178.shutdown == (BIO **)0x0) ||
           (pBVar23 = *(BIO **)BStack_1178.shutdown, pBVar23 == (BIO *)0x0)) &&
          (pBVar23 = (BIO *)(*(code *)PTR_ASN1_STRING_new_006a8790)(), pBVar23 == (BIO *)0x0)) {
    pBVar2 = (BIO *)0x0;
    unaff_s0 = pBVar23;
    in = pBVar17;
    BStack_1178.flags = (int)in_a3;
  }
  else {
    pBStack_11c0 = (BIO *)auStack_10fc;
    pBStack_1220 = (BIO *)(auStack_1104 + 4);
    pcStack_1214 = auStack_1104;
    pBStack_1108 = (BIO *)pBStack_1124->method;
    BStack_1178.num_read = (ulong)pBVar17;
    uVar4 = (**(code **)(puStack_1138 + -0x6e30))(&pBStack_1108);
    unaff_s0 = pBVar23;
    if ((uVar4 & 0x80) == 0) {
      unaff_s4 = auStack_1104._4_4_;
      if (auStack_1104._4_4_ == (BIO *)in_a3) {
        if ((uVar4 & 0x20) != 0) {
          pbStack_10c4 = (bio_st *)0x0;
          pBStack_10a8 = pBStack_1124;
          auStack_10d8._12_4_ = pBStack_1108;
          pBStack_10b4 = auStack_1104._0_4_;
          pBStack_10b8 = local_1038;
          if (pBVar17 == (BIO *)0x0) {
            pbStack_10b0 = (bio_st *)0x0;
          }
          else {
            pbStack_10b0 = (bio_st *)((int)&pBVar17->method + (int)&pBStack_1108->method);
          }
          auStack_1104._4_4_ = (BIO *)0x0;
          pBStack_112c = (BIO *)0x0;
          p_Stack_10e4 = (_func_603 *)0x0;
          unaff_s7 = (bio_st *)(auStack_10d8 + 0xc);
          pbStack_10dc = (bio_st *)0x0;
          unaff_s6 = (BIO *)auStack_10ec;
          pbStack_10e0 = (bio_st *)0x0;
          unaff_s8 = (BIO *)(auStack_10f4 + 4);
          pcStack_110c = "a_bytes.c";
          uVar6 = uVar4 & 1;
          uStack_10c0 = uVar4;
          pBStack_10bc = (BIO *)in_a3;
          do {
            if (uVar6 == 0) {
              if (0 < (int)pBStack_10b4) goto LAB_0060e128;
LAB_0060e2f0:
              pBVar17 = (BIO *)(auStack_10d8 + 0xc);
              iVar3 = (**(code **)(puStack_1138 + -0x69e4))(pBVar17);
              if (iVar3 != 0) {
                pBVar23->method = (BIO_METHOD *)auStack_1104._4_4_;
                if ((_func_595 *)pBVar23->cb_arg != (_func_595 *)0x0) {
                  (**(code **)(puStack_1138 + -0x7f58))();
                }
                pBVar23->cb_arg = (char *)pbStack_10e0;
                pBVar2 = auStack_10d8._12_4_;
                if (pBStack_112c != (BIO *)0x0) {
                  (**(code **)(puStack_1138 + -0x6644))(pBStack_112c);
                  pBVar2 = auStack_10d8._12_4_;
                }
                goto LAB_0060e288;
              }
LAB_0060e1b0:
              if (pBStack_112c != (BIO *)0x0) goto LAB_0060e1b8;
              goto LAB_0060e1cc;
            }
            pcStack_1214 = (char *)((int)pbStack_10b0 - (int)auStack_10d8._12_4_);
            pbStack_10c8 = (bio_st *)(**(code **)(puStack_1138 + -0x69e0))(unaff_s7);
            if (pbStack_10c8 != (bio_st *)0x0) goto LAB_0060e2f0;
LAB_0060e128:
            unaff_s5 = pBStack_10b8;
            pBVar17 = (BIO *)(auStack_10d8 + 0xc);
            pBStack_1128 = pBStack_10bc;
            pBStack_10ac = auStack_10d8._12_4_;
            in_a3 = (char *)((int)pbStack_10b0 - (int)auStack_10d8._12_4_);
            if (iStack_1034 == 0x14) {
              pbStack_10c4 = (bio_st *)0xc5;
              goto LAB_0060e1b0;
            }
            pBVar17 = pBStack_112c;
            if ((pBStack_112c == (BIO *)0x0) &&
               (pBVar17 = (BIO *)(**(code **)(puStack_1138 + -0x6650))(), pBVar17 == (BIO *)0x0))
            goto LAB_0060e1cc;
            pcStack_1214 = auStack_10fc + 8;
            pBStack_10f8 = auStack_10d8._12_4_;
            pBStack_1220 = unaff_s8;
            pBStack_11c0 = unaff_s6;
            BStack_1178.num_read = (ulong)in_a3;
            uVar4 = (**(code **)(puStack_1138 + -0x6e30))(auStack_10fc + 4);
            if ((uVar4 & 0x80) != 0) {
              pbStack_10c4 = (bio_st *)0x66;
LAB_0060e194:
              if (pBVar17 != pBStack_112c) {
                (**(code **)(puStack_1138 + -0x6644))(pBVar17);
              }
              goto LAB_0060e1b0;
            }
            if (pBStack_1128 != auStack_10f4._4_4_) {
              pbStack_10c4 = (bio_st *)&DAT_000000a8;
              goto LAB_0060e194;
            }
            if ((uVar4 & 0x20) == 0) {
              if (auStack_10f4._0_4_ == (BIO *)0x0) {
                if (pBVar17->cb_arg == (char *)0x0) {
                  in_a3 = (char *)0x0;
                  auStack_10d8._12_4_ = pBStack_10f8;
                }
                else {
                  in_a3 = (char *)0x0;
                  (**(code **)(puStack_1138 + -0x7f58))();
                  auStack_10d8._12_4_ = pBStack_10f8;
                }
              }
              else {
                if (((int)pBVar17->method < (int)auStack_10f4._0_4_) ||
                   (in_a3 = pBVar17->cb_arg, (BIO *)in_a3 == (BIO *)0x0)) {
                  pBStack_1220 = (BIO *)&DAT_000000e9;
                  pcStack_1214 = pcStack_110c;
                  in_a3 = (char *)(**(code **)(puStack_1138 + -0x7dd8))
                                            ((undefined *)((int)&(auStack_10f4._0_4_)->method + 1));
                  if ((BIO *)in_a3 == (BIO *)0x0) {
                    pbStack_10c4 = (bio_st *)&DAT_00000041;
                    goto LAB_0060e194;
                  }
                  if (pBVar17->cb_arg != (char *)0x0) {
                    (**(code **)(puStack_1138 + -0x7f58))();
                  }
                }
                pBStack_1220 = auStack_10f4._0_4_;
                (**(code **)(puStack_1138 + -0x52f4))(in_a3,pBStack_10f8);
                *(undefined *)((int)&(auStack_10f4._0_4_)->method + (int)(BIO_METHOD **)in_a3) = 0;
                auStack_10d8._12_4_ =
                     (BIO *)((int)&(auStack_10f4._0_4_)->method + (int)&pBStack_10f8->method);
              }
              pBVar17->method = (BIO_METHOD *)auStack_10f4._0_4_;
              pBVar17->cb_arg = in_a3;
              pBVar17->callback = (_func_603 *)pBStack_1128;
              pBVar2 = auStack_10f4._0_4_;
            }
            else {
              pbStack_1098 = (bio_st *)0x0;
              auStack_10a0._0_4_ = pBStack_10f8;
              pBStack_1088 = auStack_10f4._0_4_;
              pBStack_1090 = pBStack_1128;
              pBStack_108c = unaff_s5;
              if ((BIO *)in_a3 == (BIO *)0x0) {
                puStack_1084 = (undefined *)0x0;
              }
              else {
                puStack_1084 = (undefined *)((int)pBStack_10f8 + (int)in_a3);
              }
              pBStack_1118 = (BIO *)auStack_10a0;
              pBStack_1128 = (BIO *)0x0;
              auStack_10ec._4_4_ = (BIO **)0x0;
              unaff_s5 = (BIO *)(auStack_10ec + 4);
              puStack_1114 = auStack_10a0 + 8;
              auStack_10d8._0_4_ = (bio_st *)0x0;
              in_a3 = auStack_10d8;
              auStack_10d8._8_4_ = (char *)0x0;
              auStack_10d8._4_4_ = (bio_st *)0x0;
              iStack_1110 = iStack_1034 + 2;
              pcStack_1214 = (char *)auStack_10f4._0_4_;
              uStack_1094 = uVar4;
              pbStack_107c = unaff_s7;
              if ((uVar4 & 1) != 0) goto LAB_0060e4a8;
              while (pcVar26 = *(code **)(puStack_1138 + -0x69e4), 0 < (int)pBStack_1088) {
                while( true ) {
                  BStack_1178.ex_data.sk = (stack_st_void *)puStack_1114;
                  BStack_1178.num_read = (ulong)pBStack_108c;
                  pBStack_1220 = (BIO *)(puStack_1084 + -(int)auStack_10a0._0_4_);
                  pBStack_1080 = auStack_10a0._0_4_;
                  BStack_1178.num_write = iStack_1110;
                  pcStack_1214 = (char *)pBStack_1118;
                  pBStack_11c0 = pBStack_1090;
                  iVar3 = int_d2i_ASN1_bytes(unaff_s5);
                  if (iVar3 == 0) goto LAB_0060e610;
                  pcStack_1214 = (char *)((int)&(*auStack_10ec._4_4_)->method +
                                         (int)&pBStack_1128->method);
                  iVar3 = (**(code **)(puStack_1138 + -0x72a0))(in_a3);
                  if (iVar3 == 0) {
                    pbStack_1098 = (bio_st *)&DAT_00000007;
                    goto LAB_0060e610;
                  }
                  pBStack_1220 = *auStack_10ec._4_4_;
                  pcStack_1214 = (char *)auStack_10ec._4_4_[2];
                  (**(code **)(puStack_1138 + -0x52f4))
                            ((char *)((int)&pBStack_1128->method +
                                     (int)&(auStack_10d8._4_4_)->method));
                  if ((uStack_1094 & 1) == 0) {
                    pcStack_1214 = (char *)((int)auStack_10a0._0_4_ - (int)pBStack_1080);
                    pBStack_1088 = (BIO *)((int)pBStack_1088 - (int)pcStack_1214);
                  }
                  pBStack_1128 = (BIO *)((int)&(*auStack_10ec._4_4_)->method +
                                        (int)&pBStack_1128->method);
                  if ((uStack_1094 & 1) == 0) break;
LAB_0060e4a8:
                  pcStack_1214 = puStack_1084 + -(int)auStack_10a0._0_4_;
                  auStack_10a0._4_4_ =
                       (_func_603 *)(**(code **)(puStack_1138 + -0x69e0))(pBStack_1118);
                  if (auStack_10a0._4_4_ != (_func_603 *)0x0) {
                    pcVar26 = *(code **)(puStack_1138 + -0x69e4);
                    goto LAB_0060e4d0;
                  }
                }
              }
LAB_0060e4d0:
              iVar3 = (*pcVar26)(pBStack_1118);
              if (iVar3 == 0) {
LAB_0060e610:
                if (auStack_10ec._4_4_ != (BIO **)0x0) {
                  (**(code **)(puStack_1138 + -0x6644))();
                }
                if (auStack_10d8._4_4_ != (bio_st *)0x0) {
                  (**(code **)(puStack_1138 + -0x7f58))();
                }
                pbStack_10c4 = pbStack_1098;
                goto LAB_0060e194;
              }
              pBVar17->method = (BIO_METHOD *)pBStack_1128;
              if (pBVar17->cb_arg != (char *)0x0) {
                (**(code **)(puStack_1138 + -0x7f58))();
              }
              pBVar17->cb_arg = (char *)auStack_10d8._4_4_;
              if (auStack_10ec._4_4_ != (BIO **)0x0) {
                (**(code **)(puStack_1138 + -0x6644))();
              }
              auStack_10d8._12_4_ = auStack_10a0._0_4_;
              pBVar2 = (BIO *)pBVar17->method;
            }
            pcStack_1214 = (char *)((int)&pBVar2->method + (int)&(auStack_1104._4_4_)->method);
            iVar3 = (**(code **)(puStack_1138 + -0x72a0))(&p_Stack_10e4);
            if (iVar3 == 0) goto LAB_0060e67c;
            pBStack_1220 = (BIO *)pBVar17->method;
            pcStack_1214 = pBVar17->cb_arg;
            (**(code **)(puStack_1138 + -0x52f4))
                      ((code *)((int)&(auStack_1104._4_4_)->method + (int)&pbStack_10e0->method));
            uVar6 = uStack_10c0 & 1;
            if (uVar6 == 0) {
              pcStack_1214 = (char *)((int)auStack_10d8._12_4_ - (int)pBStack_10ac);
              pBStack_10b4 = (BIO *)((int)pBStack_10b4 - (int)pcStack_1214);
            }
            auStack_1104._4_4_ = (BIO *)((int)&(auStack_1104._4_4_)->method + (int)pBVar17->method);
            pBStack_112c = pBVar17;
          } while( true );
        }
        if (auStack_1104._0_4_ == (BIO *)0x0) {
          if ((_func_595 *)pBVar23->cb_arg == (_func_595 *)0x0) {
            pBVar17 = (BIO *)0x0;
            pBVar2 = pBStack_1108;
          }
          else {
            pBVar17 = (BIO *)0x0;
            (**(code **)(puStack_1138 + -0x7f58))();
            pBVar2 = pBStack_1108;
          }
        }
        else {
          if ((int)pBVar23->method < (int)auStack_1104._0_4_) {
            pcVar26 = *(code **)(puStack_1138 + -0x7dd8);
LAB_0060e690:
            pBStack_1220 = (BIO *)&DAT_000000e9;
            pcStack_1214 = "a_bytes.c";
            pBVar17 = (BIO *)(*pcVar26)((undefined *)((int)&(auStack_1104._0_4_)->method + 1));
            if (pBVar17 == (BIO *)0x0) {
              *ppbStack_111c = (bio_st *)&DAT_00000041;
              goto LAB_0060e014;
            }
            if ((_func_595 *)pBVar23->cb_arg != (_func_595 *)0x0) {
              (**(code **)(puStack_1138 + -0x7f58))();
            }
          }
          else {
            pBVar17 = (BIO *)pBVar23->cb_arg;
            pcVar26 = *(code **)(puStack_1138 + -0x7dd8);
            if (pBVar17 == (BIO *)0x0) goto LAB_0060e690;
          }
          pcStack_1214 = (char *)pBStack_1108;
          pBStack_1220 = auStack_1104._0_4_;
          (**(code **)(puStack_1138 + -0x52f4))(pBVar17);
          *(code *)((int)&(auStack_1104._0_4_)->method + (int)&pBVar17->method) = (code)0x0;
          pBVar2 = (BIO *)((int)&(auStack_1104._0_4_)->method + (int)&pBStack_1108->method);
        }
        pBVar23->method = (BIO_METHOD *)auStack_1104._0_4_;
        pBVar23->cb_arg = (char *)pBVar17;
        pBVar23->callback = (_func_603 *)auStack_1104._4_4_;
LAB_0060e288:
        if ((BIO **)BStack_1178.shutdown != (BIO **)0x0) {
          *(BIO **)BStack_1178.shutdown = pBVar23;
        }
        pBStack_1124->method = (BIO_METHOD *)pBVar2;
        pBVar2 = pBVar23;
        in = pBVar17;
        BStack_1178.flags = (int)in_a3;
        unaff_s4 = auStack_1104._4_4_;
        goto LAB_0060e038;
      }
      *ppbStack_111c = (bio_st *)&DAT_000000a8;
    }
    else {
      *ppbStack_111c = (bio_st *)0x66;
    }
LAB_0060e014:
    BStack_1178.flags = (int)in_a3;
    in = pBVar17;
    if (((BIO **)BStack_1178.shutdown == (BIO **)0x0) ||
       (pBVar2 = (BIO *)0x0, pBVar23 != *(BIO **)BStack_1178.shutdown)) {
      (**(code **)(puStack_1138 + -0x6644))(pBVar23);
      pBVar2 = (BIO *)0x0;
    }
  }
LAB_0060e038:
  if (ppBStack_1074 == (BIO **)*puStack_1120) {
    return (int)pBVar2;
  }
  BStack_1178.num = (int)d2i_ASN1_type_bytes;
  ppBStack_121c = ppBStack_1074;
  (**(code **)(puStack_1138 + -0x5330))();
  puStack_11c8 = PTR___stack_chk_guard_006a9ae8;
  pBStack_1184 = (BIO *)*(BIO_METHOD **)pcStack_1214;
  pcVar21 = auStack_1180 + 8;
  puStack_1198 = &_gp;
  pBVar2 = (BIO *)auStack_1180;
  BStack_1178.callback = *(_func_603 **)PTR___stack_chk_guard_006a9ae8;
  pBStack_11a0 = pBStack_1220;
  BStack_1178.cb_arg = (char *)unaff_s0;
  BStack_1178.init = (int)in;
  BStack_1178.retry_reason = (int)unaff_s4;
  uVar4 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pBStack_1184,pBVar2,auStack_1180 + 4);
  if ((uVar4 & 0x80) == 0) {
    pBVar17 = (BIO *)0x99;
    if (0x1f < (int)p_Stack_117c) goto LAB_0060e7d0;
    uVar4 = (**(code **)(puStack_1198 + -0x60f8))();
    if (((uint)pBStack_11c0 & uVar4) == 0) {
      pBVar17 = (BIO *)0xa9;
      goto LAB_0060e7d0;
    }
    if (p_Stack_117c != (_func_603 *)0x3) {
      if (((ppBStack_121c == (BIO **)0x0) ||
          (pBStack_1220 = *ppBStack_121c, pBStack_1220 == (BIO *)0x0)) &&
         (pBStack_1220 = (BIO *)(**(code **)(puStack_1198 + -0x6650))(), pBStack_1220 == (BIO *)0x0)
         ) {
        pBVar23 = (BIO *)0x0;
        goto LAB_0060e7f8;
      }
      pBStack_11c0 = (BIO *)0x0;
      if (auStack_1180 == (undefined  [4])0x0) {
LAB_0060e874:
        if (pBStack_1220->cb_arg != (char *)0x0) {
          (**(code **)(puStack_1198 + -0x7f58))();
        }
        pBStack_1220->cb_arg = (char *)pBStack_11c0;
        pBStack_1220->method = (BIO_METHOD *)auStack_1180;
        pBStack_1220->callback = p_Stack_117c;
        if (ppBStack_121c != (BIO **)0x0) {
          *ppBStack_121c = pBStack_1220;
        }
        *(BIO_METHOD **)pcStack_1214 = (BIO_METHOD *)pBStack_1184;
        pBVar23 = pBStack_1220;
        goto LAB_0060e7f8;
      }
      pBStack_118c = (BIO *)0x680000;
      pBStack_11c0 = (BIO *)(**(code **)(puStack_1198 + -0x7dd8))
                                      ((undefined *)((int)(BIO_METHOD **)auStack_1180 + 1),
                                       "a_bytes.c",0x6b);
      if (pBStack_11c0 != (BIO *)0x0) {
        pBVar2 = pBStack_1184;
        pBVar17 = (BIO *)auStack_1180;
        pcVar21 = (char *)pBStack_118c;
        (**(code **)(puStack_1198 + -0x52f4))(pBStack_11c0);
        *(undefined *)((int)(BIO_METHOD **)auStack_1180 + (int)&pBStack_11c0->method) = 0;
        pBStack_1184 = (BIO *)((int)(BIO_METHOD **)auStack_1180 + (int)&pBStack_1184->method);
        goto LAB_0060e874;
      }
      pcVar21 = (char *)&pBStack_118c[-0x189].ptr;
      pBVar17 = (BIO *)&DAT_00000041;
      pBVar2 = (BIO *)&DAT_00000095;
      pBStack_11a0 = (BIO *)&DAT_00000080;
      (**(code **)(puStack_1198 + -0x6eac))(0xd);
      if ((ppBStack_121c == (BIO **)0x0) || (pBStack_1220 != *ppBStack_121c)) {
        (**(code **)(puStack_1198 + -0x6644))(pBStack_1220);
        pBVar23 = (BIO *)0x0;
        goto LAB_0060e7f8;
      }
      goto LAB_0060e7f4;
    }
    pBVar2 = (BIO *)pcStack_1214;
    pBVar17 = pBStack_1220;
    pBVar23 = (BIO *)(**(code **)(puStack_1198 + -0x55e8))(ppBStack_121c);
  }
  else {
    pBVar17 = (BIO *)0x0;
LAB_0060e7d0:
    pBVar2 = (BIO *)&DAT_00000095;
    pcVar21 = "a_bytes.c";
    pBStack_11a0 = (BIO *)&DAT_00000080;
    (**(code **)(puStack_1198 + -0x6eac))(0xd);
LAB_0060e7f4:
    pBVar23 = (BIO *)0x0;
  }
LAB_0060e7f8:
  if ((BIO *)BStack_1178.callback == *(BIO **)puStack_11c8) {
    return (int)pBVar23;
  }
  pcStack_11b4 = i2d_ASN1_bytes;
  pBVar23 = (BIO *)BStack_1178.callback;
  (**(code **)(puStack_1198 + -0x5330))();
  pBStack_1354 = (BIO *)PTR___stack_chk_guard_006a9ae8;
  puStack_11e0 = &_gp;
  ppiStack_11d4 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  ppBVar5 = (BIO **)0x0;
  pBVar14 = pBVar2;
  pBStack_13e0 = pBVar17;
  pBVar22 = (BIO *)pcVar21;
  pBStack_1218 = (BIO *)puStack_11c8;
  pBStack_11d0 = pBStack_1220;
  ppBStack_11cc = ppBStack_121c;
  pBStack_11c4 = (BIO *)pcStack_1214;
  pBStack_11bc = unaff_s5;
  pBStack_11b8 = unaff_s6;
  if (pBVar23 != (BIO *)0x0) {
    pBStack_1218 = pBVar17;
    if (pBVar17 == (BIO *)0x3) {
      ppBVar5 = (BIO **)(*(code *)PTR_i2d_ASN1_BIT_STRING_006a97fc)();
      pBVar14 = pBVar2;
      pBVar22 = (BIO *)pcVar21;
    }
    else {
      pBVar25 = (BIO *)pBVar23->method;
      pBVar14 = pBVar25;
      ppBVar5 = (BIO **)(*(code *)PTR_ASN1_object_size_006a83e4)(0);
      pBStack_1220 = pBVar23;
      ppBStack_121c = ppBVar5;
      pcStack_1214 = (char *)pBVar2;
      unaff_s5 = pBVar25;
      unaff_s6 = (BIO *)pcVar21;
      if (pBVar2 != (BIO *)0x0) {
        pBStack_11d8 = pBVar2->method;
        pBVar22 = pBVar17;
        pBStack_11e8 = (BIO *)pcVar21;
        (**(code **)(puStack_11e0 + -0x69f8))
                  (&pBStack_11d8,&pBVar17[-1].num_read < &SUB_00000002,pBVar25);
        pBStack_13e0 = (BIO *)pBVar23->method;
        pBVar14 = (BIO *)pBVar23->cb_arg;
        (**(code **)(puStack_11e0 + -0x52f4))(pBStack_11d8);
        pBVar2->method = (BIO_METHOD *)((int)&pBVar23->method->type + (int)&pBStack_11d8->type);
      }
    }
  }
  if (ppiStack_11d4 == *(int ***)pBStack_1354) {
    return (int)ppBVar5;
  }
  pcStack_11fc = d2i_ASN1_bytes;
  ppiStack_135c = ppiStack_11d4;
  (**(code **)(puStack_11e0 + -0x5330))();
  ppuStack_12c8 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  puStack_1210 = (undefined *)pBStack_1354;
  puStack_12e0 = &_gp;
  puStack_1224 = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pcVar21 = (char *)pBVar22;
  pBStack_1358 = pBVar22;
  pBStack_12cc = pBVar14;
  pBStack_120c = unaff_s5;
  pBStack_1208 = unaff_s6;
  pbStack_1204 = unaff_s7;
  pBStack_1200 = unaff_s8;
  if (ppiStack_135c == (int **)0x0) {
LAB_0060ebd4:
    pcStack_13d0 = (char *)pBStack_13e0;
    ppBStack_1308 = (BIO **)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_13d4 = (char *)pBVar14;
    if (ppBStack_1308 != (BIO **)0x0) {
      pcVar21 = auStack_12ac;
      pcStack_13d0 = auStack_12b4 + 4;
      pcStack_13d4 = auStack_12b4;
      pBStack_12b8 = (BIO *)pBStack_12cc->method;
      pBStack_12f0 = pBStack_13e0;
      uVar4 = (**(code **)(puStack_12e0 + -0x6e30))(&pBStack_12b8);
      ppBVar5 = ppBStack_1308;
      if ((uVar4 & 0x80) == 0) goto LAB_0060ec1c;
      pBStack_13e0 = (BIO *)0x66;
      goto LAB_0060ec2c;
    }
    goto LAB_0060eb90;
  }
  ppBStack_1308 = (BIO **)*ppiStack_135c;
  pcVar21 = auStack_12ac;
  if (ppBStack_1308 == (BIO **)0x0) goto LAB_0060ebd4;
  pBStack_12b8 = (BIO *)pBVar14->method;
  pcStack_13d0 = auStack_12b4 + 4;
  pcStack_13d4 = auStack_12b4;
  pBStack_12f0 = pBStack_13e0;
  uVar4 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pBStack_12b8);
  ppBVar5 = ppBStack_1308;
  if ((uVar4 & 0x80) != 0) {
    pBStack_13e0 = (BIO *)0x66;
    if (ppBStack_1308 != (BIO **)*ppiStack_135c) {
      pcVar26 = *(code **)(puStack_12e0 + -0x6644);
      goto LAB_0060eb80;
    }
    goto LAB_0060ec50;
  }
LAB_0060ec1c:
  ppBStack_1308 = ppBVar5;
  if (pBVar22 != auStack_12b4._4_4_) {
    pBStack_13e0 = (BIO *)&DAT_000000a8;
    goto LAB_0060ec2c;
  }
  if ((uVar4 & 0x20) != 0) {
    auStack_127c._8_4_ = (BIO *)0x0;
    auStack_127c._36_4_ = pBStack_12cc;
    auStack_127c._0_4_ = pBStack_12b8;
    auStack_127c._24_4_ = auStack_12b4._0_4_;
    auStack_127c._20_4_ = pBStack_11e8;
    if (pBStack_13e0 == (BIO *)0x0) {
      auStack_127c._28_4_ = (undefined *)0x0;
    }
    else {
      auStack_127c._28_4_ = (undefined *)((int)&pBStack_13e0->method + (int)&pBStack_12b8->method);
    }
    pBStack_1354 = (BIO *)0x0;
    ppBStack_12d0 = (BIO **)0x0;
    p_Stack_1294 = (_func_603 *)0x0;
    unaff_s7 = (bio_st *)auStack_127c;
    pbStack_128c = (bio_st *)0x0;
    unaff_s6 = (BIO *)auStack_129c;
    pBStack_1290 = (BIO *)0x0;
    pBStack_1358 = (BIO *)(auStack_12a4 + 4);
    pcStack_12bc = "a_bytes.c";
    uVar6 = uVar4 & 1;
    auStack_127c._12_4_ = uVar4;
    auStack_127c._16_4_ = pBVar22;
    do {
      if (uVar6 == 0) {
        if (0 < (int)auStack_127c._24_4_) goto LAB_0060ed04;
LAB_0060eea4:
        pBStack_13e0 = (BIO *)auStack_127c;
        iVar3 = (**(code **)(puStack_12e0 + -0x69e4))(pBStack_13e0);
        if (iVar3 != 0) {
          *ppBVar5 = pBStack_1354;
          if (ppBVar5[2] != (BIO *)0x0) {
            (**(code **)(puStack_12e0 + -0x7f58))();
          }
          ppBVar5[2] = pBStack_1290;
          pBVar2 = auStack_127c._0_4_;
          if (ppBStack_12d0 != (BIO **)0x0) {
            (**(code **)(puStack_12e0 + -0x6644))(ppBStack_12d0);
            pBVar2 = auStack_127c._0_4_;
          }
          goto LAB_0060ee40;
        }
LAB_0060ed80:
        if (ppBStack_12d0 != (BIO **)0x0) goto LAB_0060ed88;
        goto LAB_0060ed9c;
      }
      pcStack_13d4 = auStack_127c._28_4_ + -(int)auStack_127c._0_4_;
      auStack_127c._4_4_ = (bio_st *)(**(code **)(puStack_12e0 + -0x69e0))(unaff_s7);
      if (auStack_127c._4_4_ != (bio_st *)0x0) goto LAB_0060eea4;
LAB_0060ed04:
      pBVar2 = auStack_127c._16_4_;
      pBStack_12d4 = auStack_127c._20_4_;
      auStack_127c._32_4_ = auStack_127c._0_4_;
      unaff_s5 = (BIO *)(auStack_127c._28_4_ + -(int)auStack_127c._0_4_);
      ppBVar8 = ppBStack_12d0;
      if ((ppBStack_12d0 == (BIO **)0x0) &&
         (ppBVar8 = (BIO **)(**(code **)(puStack_12e0 + -0x6650))(), ppBVar8 == (BIO **)0x0))
      goto LAB_0060ed9c;
      pcStack_13d4 = auStack_12ac + 8;
      pBStack_12a8 = auStack_127c._0_4_;
      pcStack_13d0 = (char *)pBStack_1358;
      pcVar21 = (char *)unaff_s6;
      pBStack_12f0 = unaff_s5;
      psVar7 = (stack_st_void *)(**(code **)(puStack_12e0 + -0x6e30))(auStack_12ac + 4);
      if (((uint)psVar7 & 0x80) != 0) {
        auStack_127c._8_4_ = (BIO *)0x66;
LAB_0060ed64:
        if (ppBVar8 != ppBStack_12d0) {
          (**(code **)(puStack_12e0 + -0x6644))(ppBVar8);
        }
        goto LAB_0060ed80;
      }
      if (pBVar2 != auStack_12a4._4_4_) {
        auStack_127c._8_4_ = (BIO *)&DAT_000000a8;
        goto LAB_0060ed64;
      }
      if (((uint)psVar7 & 0x20) == 0) {
        if (auStack_12a4._0_4_ == (BIO *)0x0) {
          if (ppBVar8[2] == (BIO *)0x0) {
            unaff_s5 = (BIO *)0x0;
            auStack_127c._0_4_ = pBStack_12a8;
          }
          else {
            unaff_s5 = (BIO *)0x0;
            (**(code **)(puStack_12e0 + -0x7f58))();
            auStack_127c._0_4_ = pBStack_12a8;
          }
        }
        else {
          if (((int)*ppBVar8 < (int)auStack_12a4._0_4_) ||
             (unaff_s5 = ppBVar8[2], unaff_s5 == (BIO *)0x0)) {
            pcStack_13d0 = &DAT_000000e9;
            pcStack_13d4 = pcStack_12bc;
            unaff_s5 = (BIO *)(**(code **)(puStack_12e0 + -0x7dd8))
                                        ((undefined *)((int)&(auStack_12a4._0_4_)->method + 1));
            if (unaff_s5 == (BIO *)0x0) {
              auStack_127c._8_4_ = (BIO *)&DAT_00000041;
              goto LAB_0060ed64;
            }
            if (ppBVar8[2] != (BIO *)0x0) {
              (**(code **)(puStack_12e0 + -0x7f58))();
            }
          }
          pcStack_13d0 = (char *)auStack_12a4._0_4_;
          (**(code **)(puStack_12e0 + -0x52f4))(unaff_s5,pBStack_12a8);
          *(undefined *)((int)&(auStack_12a4._0_4_)->method + (int)&unaff_s5->method) = 0;
          auStack_127c._0_4_ =
               (BIO *)((int)&(auStack_12a4._0_4_)->method + (int)&pBStack_12a8->method);
        }
        *ppBVar8 = auStack_12a4._0_4_;
        ppBVar8[2] = unaff_s5;
        ppBVar8[1] = pBVar2;
        pBVar2 = auStack_12a4._0_4_;
      }
      else {
        pBStack_1248 = (BIO *)0x0;
        auStack_127c._44_4_ = pBStack_12a8;
        pBStack_1238 = auStack_12a4._0_4_;
        pBStack_1240 = pBVar2;
        pBStack_123c = pBStack_12d4;
        if (unaff_s5 == (BIO *)0x0) {
          puStack_1234 = (undefined *)0x0;
        }
        else {
          puStack_1234 = (undefined *)((int)&unaff_s5->method + (int)&pBStack_12a8->method);
        }
        pBStack_12c4 = (BIO *)(auStack_127c + 0x2c);
        pBStack_12d4 = (BIO *)0x0;
        auStack_129c._4_4_ = (BIO **)0x0;
        unaff_s5 = (BIO *)(auStack_129c + 4);
        ppBStack_12c0 = &pBStack_1248;
        pbStack_1288 = (bio_st *)0x0;
        uStack_1280 = 0;
        pBStack_1284 = (BIO *)0x0;
        pcStack_13d4 = (char *)auStack_12a4._0_4_;
        psStack_1244 = psVar7;
        pbStack_122c = unaff_s7;
        if (((uint)psVar7 & 1) != 0) goto LAB_0060f054;
        while (pcVar26 = *(code **)(puStack_12e0 + -0x69e4), 0 < (int)pBStack_1238) {
          while( true ) {
            ppBStack_12e8 = ppBStack_12c0;
            pBStack_12f0 = pBStack_123c;
            pcStack_13d0 = puStack_1234 + -(int)auStack_127c._44_4_;
            pBStack_1230 = auStack_127c._44_4_;
            uStack_12ec = 2;
            pcStack_13d4 = (char *)pBStack_12c4;
            pcVar21 = (char *)pBStack_1240;
            iVar3 = int_d2i_ASN1_bytes(unaff_s5);
            if (iVar3 == 0) goto LAB_0060f1ac;
            pcStack_13d4 = (char *)((int)&(*auStack_129c._4_4_)->method + (int)&pBStack_12d4->method
                                   );
            iVar3 = (**(code **)(puStack_12e0 + -0x72a0))(&pbStack_1288);
            if (iVar3 == 0) {
              pBStack_1248 = (BIO *)&DAT_00000007;
              goto LAB_0060f1ac;
            }
            pcStack_13d0 = (char *)*auStack_129c._4_4_;
            pcStack_13d4 = (char *)auStack_129c._4_4_[2];
            (**(code **)(puStack_12e0 + -0x52f4))
                      ((undefined *)((int)&pBStack_12d4->method + (int)&pBStack_1284->method));
            if (((uint)psStack_1244 & 1) == 0) {
              pcStack_13d4 = (char *)((int)auStack_127c._44_4_ - (int)pBStack_1230);
              pBStack_1238 = (BIO *)((int)pBStack_1238 - (int)pcStack_13d4);
            }
            pBStack_12d4 = (BIO *)((int)&(*auStack_129c._4_4_)->method + (int)&pBStack_12d4->method)
            ;
            if (((uint)psStack_1244 & 1) == 0) break;
LAB_0060f054:
            pcStack_13d4 = puStack_1234 + -(int)auStack_127c._44_4_;
            uStack_124c = (**(code **)(puStack_12e0 + -0x69e0))(pBStack_12c4);
            if (uStack_124c != 0) {
              pcVar26 = *(code **)(puStack_12e0 + -0x69e4);
              goto LAB_0060f07c;
            }
          }
        }
LAB_0060f07c:
        iVar3 = (*pcVar26)(pBStack_12c4);
        if (iVar3 == 0) {
LAB_0060f1ac:
          if (auStack_129c._4_4_ != (BIO **)0x0) {
            (**(code **)(puStack_12e0 + -0x6644))();
          }
          if (pBStack_1284 != (BIO *)0x0) {
            (**(code **)(puStack_12e0 + -0x7f58))();
          }
          auStack_127c._8_4_ = pBStack_1248;
          goto LAB_0060ed64;
        }
        *ppBVar8 = pBStack_12d4;
        if (ppBVar8[2] != (BIO *)0x0) {
          (**(code **)(puStack_12e0 + -0x7f58))();
        }
        ppBVar8[2] = pBStack_1284;
        if (auStack_129c._4_4_ != (BIO **)0x0) {
          (**(code **)(puStack_12e0 + -0x6644))();
        }
        auStack_127c._0_4_ = auStack_127c._44_4_;
        pBVar2 = *ppBVar8;
      }
      pcStack_13d4 = (char *)((int)&pBVar2->method + (int)&pBStack_1354->method);
      iVar3 = (**(code **)(puStack_12e0 + -0x72a0))(&p_Stack_1294);
      if (iVar3 == 0) goto LAB_0060f214;
      pcStack_13d0 = (char *)*ppBVar8;
      pcStack_13d4 = (char *)ppBVar8[2];
      (**(code **)(puStack_12e0 + -0x52f4))
                ((undefined *)((int)&pBStack_1354->method + (int)&pBStack_1290->method));
      uVar6 = auStack_127c._12_4_ & 1;
      if (uVar6 == 0) {
        pcStack_13d4 = (char *)((int)auStack_127c._0_4_ - (int)auStack_127c._32_4_);
        auStack_127c._24_4_ = (BIO *)((int)auStack_127c._24_4_ - (int)pcStack_13d4);
      }
      pBStack_1354 = (BIO *)((int)&(*ppBVar8)->method + (int)&pBStack_1354->method);
      ppBStack_12d0 = ppBVar8;
    } while( true );
  }
  if (auStack_12b4._0_4_ == (BIO *)0x0) {
    if (ppBVar5[2] == (BIO *)0x0) {
      pBStack_13e0 = (BIO *)0x0;
      pBVar2 = pBStack_12b8;
    }
    else {
      pBStack_13e0 = (BIO *)0x0;
      (**(code **)(puStack_12e0 + -0x7f58))();
      pBVar2 = pBStack_12b8;
    }
  }
  else {
    if ((int)*ppBVar5 < (int)auStack_12b4._0_4_) {
      pcVar26 = *(code **)(puStack_12e0 + -0x7dd8);
LAB_0060f228:
      pcStack_13d0 = &DAT_000000e9;
      pcStack_13d4 = "a_bytes.c";
      pBStack_13e0 = (BIO *)(*pcVar26)((undefined *)((int)&(auStack_12b4._0_4_)->method + 1));
      if (pBStack_13e0 == (BIO *)0x0) {
        pBStack_13e0 = (BIO *)&DAT_00000041;
        goto LAB_0060ec2c;
      }
      if (ppBVar5[2] != (BIO *)0x0) {
        (**(code **)(puStack_12e0 + -0x7f58))();
      }
    }
    else {
      pBStack_13e0 = ppBVar5[2];
      pcVar26 = *(code **)(puStack_12e0 + -0x7dd8);
      if (pBStack_13e0 == (BIO *)0x0) goto LAB_0060f228;
    }
    pcStack_13d4 = (char *)pBStack_12b8;
    pcStack_13d0 = (char *)auStack_12b4._0_4_;
    (**(code **)(puStack_12e0 + -0x52f4))(pBStack_13e0);
    *(undefined *)((int)&(auStack_12b4._0_4_)->method + (int)&pBStack_13e0->method) = 0;
    pBVar2 = (BIO *)((int)&(auStack_12b4._0_4_)->method + (int)&pBStack_12b8->method);
  }
  *ppBVar5 = auStack_12b4._0_4_;
  ppBVar5[2] = pBStack_13e0;
  ppBVar5[1] = pBVar22;
LAB_0060ee40:
  if (ppiStack_135c != (int **)0x0) {
    *ppiStack_135c = (int *)ppBVar5;
  }
  pBStack_12cc->method = (BIO_METHOD *)pBVar2;
  goto LAB_0060eb94;
LAB_0060e67c:
  pbStack_10c4 = (bio_st *)&DAT_00000007;
  pBStack_112c = pBVar17;
LAB_0060e1b8:
  (**(code **)(puStack_1138 + -0x6644))(pBStack_112c);
LAB_0060e1cc:
  if (pbStack_10e0 != (bio_st *)0x0) {
    (**(code **)(puStack_1138 + -0x7f58))();
  }
  *ppbStack_111c = pbStack_10c4;
  unaff_s4 = auStack_1104._4_4_;
  goto LAB_0060e014;
LAB_0060f214:
  auStack_127c._8_4_ = (BIO *)&DAT_00000007;
  ppBStack_12d0 = ppBVar8;
LAB_0060ed88:
  (**(code **)(puStack_12e0 + -0x6644))(ppBStack_12d0);
LAB_0060ed9c:
  pBStack_13e0 = auStack_127c._8_4_;
  if (pBStack_1290 != (BIO *)0x0) {
    (**(code **)(puStack_12e0 + -0x7f58))();
    pBStack_13e0 = auStack_127c._8_4_;
  }
LAB_0060ec2c:
  pcVar26 = *(code **)(puStack_12e0 + -0x6644);
  if ((ppiStack_135c == (int **)0x0) || ((BIO **)*ppiStack_135c != ppBStack_1308)) {
LAB_0060eb80:
    (*pcVar26)(ppBStack_1308);
    if (pBStack_13e0 != (BIO *)0x0) {
LAB_0060ec50:
      pcVar26 = *(code **)(puStack_12e0 + -0x6eac);
      goto LAB_0060ec58;
    }
  }
  else if (pBStack_13e0 != (BIO *)0x0) {
    pcVar26 = *(code **)(puStack_12e0 + -0x6eac);
LAB_0060ec58:
    pcStack_13d4 = (char *)0x8f;
    pcVar21 = "a_bytes.c";
    pBStack_12f0 = (BIO *)0xaf;
    pcStack_13d0 = (char *)pBStack_13e0;
    (*pcVar26)(0xd);
    ppBVar5 = (BIO **)0x0;
    goto LAB_0060eb94;
  }
LAB_0060eb90:
  ppBVar5 = (BIO **)0x0;
LAB_0060eb94:
  if (puStack_1224 == *ppuStack_12c8) {
    return (int)ppBVar5;
  }
  uStack_1304 = 0x60f2d8;
  puStack_1310 = puStack_1224;
  (**(code **)(puStack_12e0 + -0x5330))();
  pBStack_1398 = (BIO_METHOD *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_13d8 = &puStack_1310;
  psStack_130c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  psVar9 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_13d8,(long)pcStack_13d4,pcStack_13d0
                        ,(free_func *)pcVar21,0x10,0);
  if (psVar9 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pcStack_13d4 = &DAT_0000006e;
    pcStack_13d0 = "asn_pack.c";
    ppuStack_13d8 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_130c == *(stack_st_OPENSSL_BLOCK **)pBStack_1398) {
    return (int)psVar9;
  }
  pcStack_1344 = ASN1_seq_pack;
  psVar9 = psStack_130c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_13dc = PTR___stack_chk_guard_006a9ae8;
  puStack_1364 = (undefined *)pBStack_1398;
  puStack_136c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pBStack_1360 = pBStack_13e0;
  pBStack_1350 = unaff_s5;
  pBStack_134c = unaff_s6;
  pbStack_1348 = unaff_s7;
  pBVar2 = (BIO *)i2d_ASN1_SET(psVar9,(uchar **)0x0,(undefined1 *)ppuStack_13d8,0x10,0,0);
  if (pBVar2 == (BIO *)0x0) {
    pp = (BIO_METHOD **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    pBVar10 = (BIO_METHOD *)0x0;
  }
  else {
    pBStack_1398 = (BIO_METHOD *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pBVar2,"asn_pack.c",0x62);
    pBStack_13e0 = pBVar2;
    if (pBStack_1398 == (BIO_METHOD *)0x0) {
      pp = (BIO_METHOD **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      pBVar10 = (BIO_METHOD *)0x0;
    }
    else {
      pp = &pBStack_1370;
      pBStack_1370 = pBStack_1398;
      i2d_ASN1_SET(psVar9,(uchar **)pp,(undefined1 *)ppuStack_13d8,0x10,0,0);
      if ((BIO *)pcStack_13d0 != (BIO *)0x0) {
        *(BIO_METHOD **)pcStack_13d0 = (BIO_METHOD *)pBVar2;
      }
      pBVar10 = pBStack_1398;
      if ((BIO *)pcStack_13d4 != (BIO *)0x0) {
        *(BIO_METHOD **)pcStack_13d4 = pBStack_1398;
      }
    }
  }
  if (puStack_136c == *(undefined4 **)puStack_13dc) {
    return (int)pBVar10;
  }
  pcStack_1394 = ASN1_unpack_string;
  puVar15 = puStack_136c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_13e4 = PTR___stack_chk_guard_006a9ae8;
  uStack_13a0 = puVar15[2];
  ppiVar18 = (int **)*puVar15;
  puVar15 = &uStack_13a0;
  puStack_13b0 = &_gp;
  iStack_139c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)pp)(0);
  if (iVar3 == 0) {
    ppiVar18 = (int **)&DAT_0000006e;
    uStack_13b8 = 0x79;
    puVar15 = (undefined4 *)&DAT_00000088;
    iStack_13a4 = iVar3;
    (**(code **)(puStack_13b0 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    iVar3 = iStack_13a4;
  }
  if (iStack_139c == *(int *)puStack_13e4) {
    return iVar3;
  }
  pcStack_13cc = ASN1_pack_string;
  iVar3 = iStack_139c;
  (**(code **)(puStack_13b0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_13ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppiVar18 == (int **)0x0) {
    piVar24 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar24 != (int *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppiVar19 = (int **)&DAT_00000041;
    piVar16 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    piVar12 = (int *)0x0;
  }
  else {
    piVar24 = *ppiVar18;
    if (piVar24 == (int *)0x0) {
      piVar24 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar24 == (int *)0x0) goto LAB_0060f754;
      *ppiVar18 = piVar24;
    }
LAB_0060f614:
    iVar11 = (*(code *)puVar15)(iVar3,0);
    *piVar24 = iVar11;
    if (iVar11 == 0) {
      ppiVar19 = (int **)&DAT_00000070;
      piVar16 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppiVar19 = (int **)&DAT_00000092;
      iStack_13f0 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"asn_pack.c");
      if (iStack_13f0 != 0) {
        piVar16 = &iStack_13f0;
        piVar24[2] = iStack_13f0;
        (*(code *)puVar15)(iVar3,piVar16);
        piVar12 = piVar24;
        goto LAB_0060f670;
      }
      ppiVar19 = (int **)&DAT_00000041;
      piVar16 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppiVar18 == (int **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar24);
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = *ppiVar18;
      if (piVar12 == (int *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar24);
        *ppiVar18 = (int *)0x0;
      }
      else {
        piVar12 = (int *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_13ec == *(int *)puVar1) {
    return (int)piVar12;
  }
  iVar3 = iStack_13ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppiVar19 == (int **)0x0) {
    piVar24 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar24 == (int *)0x0) {
LAB_0060f874:
      uVar20 = 0x41;
      uVar13 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    piVar24 = *ppiVar19;
    if (piVar24 == (int *)0x0) {
      piVar24 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar24 == (int *)0x0) goto LAB_0060f874;
      *ppiVar19 = piVar24;
    }
  }
  if (piVar24[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    piVar24[2] = 0;
  }
  iVar3 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar3,piVar24 + 2,piVar16);
  *piVar24 = iVar3;
  if (iVar3 == 0) {
    uVar20 = 0x70;
    uVar13 = 0xba;
  }
  else {
    if (piVar24[2] != 0) {
      return (int)piVar24;
    }
    uVar20 = 0x41;
    uVar13 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar20,"asn_pack.c",uVar13);
  return 0;
}

