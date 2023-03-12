
/* WARNING: Could not reconcile some variable overlaps */

undefined * do_responder_isra_0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char **ppcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined *puVar15;
  undefined4 uVar16;
  undefined **ppuVar17;
  undefined *unaff_s1;
  int iVar18;
  undefined *puVar19;
  undefined *puVar20;
  int iVar21;
  int unaff_s3;
  undefined **ppuVar22;
  undefined *unaff_s4;
  undefined *puVar23;
  undefined **ppuVar24;
  undefined **unaff_s7;
  code *pcVar25;
  undefined *puStack_6bc;
  undefined *puStack_6b8;
  undefined *puStack_6b4;
  char *pcStack_6b0;
  int iStack_6ac;
  char *pcStack_6a8;
  undefined *puStack_6a4;
  undefined *puStack_6a0;
  char *pcStack_69c;
  undefined *puStack_698;
  char *pcStack_694;
  int iStack_690;
  undefined4 uStack_68c;
  int iStack_688;
  undefined4 uStack_684;
  undefined *puStack_678;
  int iStack_674;
  int iStack_670;
  undefined *puStack_66c;
  undefined *puStack_668;
  undefined *puStack_664;
  undefined *puStack_660;
  undefined *puStack_65c;
  int iStack_658;
  undefined4 uStack_654;
  int iStack_650;
  int iStack_648;
  uint uStack_640;
  uint uStack_63c;
  int iStack_638;
  undefined **ppuStack_634;
  undefined *puStack_62c;
  undefined *puStack_628;
  int iStack_624;
  int iStack_620;
  int iStack_61c;
  undefined *puStack_618;
  undefined *puStack_614;
  int iStack_610;
  undefined *puStack_5fc;
  undefined *puStack_5f8;
  undefined *puStack_5f4;
  int iStack_5f0;
  undefined4 uStack_5ec;
  int iStack_5e8;
  int iStack_5e4;
  undefined4 uStack_5e0;
  int iStack_5dc;
  int iStack_5d8;
  undefined4 uStack_5d4;
  int iStack_5d0;
  int iStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5c4;
  undefined4 uStack_5c0;
  undefined4 uStack_5bc;
  undefined4 uStack_5b8;
  undefined4 uStack_5b4;
  undefined4 auStack_5b0 [4];
  undefined auStack_5a0 [68];
  int iStack_55c;
  undefined *puStack_558;
  undefined4 uStack_554;
  undefined **ppuStack_550;
  int iStack_54c;
  undefined *puStack_548;
  int iStack_544;
  undefined *puStack_540;
  undefined **ppuStack_53c;
  char *pcStack_538;
  code *pcStack_534;
  undefined **ppuStack_520;
  undefined *puStack_518;
  undefined **ppuStack_510;
  int iStack_50c;
  uint uStack_504;
  undefined *puStack_500;
  undefined *puStack_4fc;
  undefined4 uStack_4f8;
  undefined *apuStack_4f4 [32];
  int iStack_474;
  undefined *puStack_470;
  undefined *puStack_46c;
  undefined4 *puStack_468;
  int iStack_464;
  undefined *puStack_460;
  undefined *puStack_45c;
  undefined4 *puStack_458;
  undefined **ppuStack_454;
  int iStack_434;
  undefined4 uStack_430;
  undefined *local_42c [256];
  int local_2c;
  
  puStack_45c = PTR___stack_chk_guard_006aabf0;
  ppuStack_550 = (undefined **)0x0;
  puVar15 = (undefined *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_3,0x65,0);
  puStack_470 = PTR_bio_err_006a7f3c;
  if (iVar2 < 1) {
    pcStack_538 = "Error accepting connection\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puStack_470);
    puVar3 = (undefined *)0x0;
  }
  else {
    unaff_s7 = local_42c;
    unaff_s1 = (undefined *)(*(code *)PTR_BIO_pop_006a8ab4)(param_3);
    puStack_470 = (undefined *)0x0;
    *param_2 = unaff_s1;
    unaff_s4 = &DAT_006447f4;
    param_2 = (undefined4 *)&DAT_0000000d;
    unaff_s3 = 10;
    do {
      puVar15 = &DAT_00000400;
      pcStack_538 = (char *)unaff_s7;
      iVar2 = (*(code *)PTR_BIO_gets_006a85d0)(unaff_s1,unaff_s7,0x400);
      if (iVar2 < 1) {
        puVar3 = (undefined *)0x1;
        goto LAB_00470dfc;
      }
      if (puStack_470 == (undefined *)0x0) {
        puVar15 = &SUB_00000004;
        iVar2 = (*(code *)PTR_strncmp_006aaa7c)(unaff_s7,&DAT_006447f4,4);
        if (iVar2 != 0) {
          pcStack_538 = "Invalid request\n";
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
          puVar3 = (undefined *)0x1;
          goto LAB_00470dfc;
        }
      }
    } while ((local_42c[0]._0_1_ != '\r') &&
            (puStack_470 = (undefined *)0x1, local_42c[0]._0_1_ != '\n'));
    ppuStack_550 = (undefined **)0x0;
    pcStack_538 = PTR_d2i_OCSP_REQUEST_006a8e80;
    puVar15 = unaff_s1;
    puStack_470 = (undefined *)
                  (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                            (PTR_OCSP_REQUEST_new_006a886c,PTR_d2i_OCSP_REQUEST_006a8e80,unaff_s1);
    puVar20 = PTR_bio_err_006a7f3c;
    if (puStack_470 == (undefined *)0x0) {
      pcStack_538 = "Error parsing OCSP request\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar20);
      puVar3 = (undefined *)0x1;
      *param_1 = 0;
      unaff_s1 = puVar20;
    }
    else {
      *param_1 = puStack_470;
      puVar3 = (undefined *)0x1;
    }
  }
LAB_00470dfc:
  if (local_2c == *(int *)puStack_45c) {
    return puVar3;
  }
  iStack_50c = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_540 = PTR___stack_chk_guard_006aabf0;
  puStack_518 = &_gp;
  iStack_474 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_46c = unaff_s1;
  puStack_468 = param_2;
  iStack_464 = unaff_s3;
  puStack_460 = unaff_s4;
  puStack_458 = param_1;
  ppuStack_454 = unaff_s7;
  iVar2 = (*(code *)PTR_BIO_new_connect_006a8e84)(puVar15);
  if (iVar2 == 0) {
    puStack_558 = (undefined *)0x0;
    pcVar14 = "Error creating connect BIO\n";
    (**(code **)(puStack_518 + -0x7fa8))(iStack_50c);
    goto LAB_00471074;
  }
  (**(code **)(puStack_518 + -0x7fc8))(iVar2,100,1,&_gp);
  if (iStack_434 != 1) {
    iStack_434 = 0;
LAB_00470fa8:
    puStack_500 = (undefined *)0x0;
    if (local_42c[0] == (undefined *)0xffffffff) {
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x65,0,0);
      if (iVar4 < 1) {
LAB_00471484:
        (**(code **)(puStack_518 + -0x7e88))(iStack_50c,"Error connecting BIO\n");
      }
      else {
        iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
        if (iVar4 < 1) goto LAB_0047102c;
LAB_004710ec:
        ppuStack_550 = (undefined **)
                       (**(code **)(puStack_518 + -0x7058))(iVar2,ppuStack_550,0,0xffffffff);
        if (ppuStack_550 != (undefined **)0x0) {
          for (iVar4 = 0; iVar6 = (**(code **)(puStack_518 + -0x7fb4))(uStack_430), iVar4 < iVar6;
              iVar4 = iVar4 + 1) {
            iVar6 = (**(code **)(puStack_518 + -0x7fbc))(uStack_430,iVar4);
            pcVar14 = *(char **)(iVar6 + 4);
            iVar6 = (**(code **)(puStack_518 + -0x7054))
                              (ppuStack_550,pcVar14,*(undefined4 *)(iVar6 + 8));
            if (iVar6 == 0) goto LAB_0047127c;
          }
          pcVar14 = pcStack_538;
          iVar4 = (**(code **)(puStack_518 + -0x7050))(ppuStack_550);
          if (iVar4 != 0) {
            ppuStack_510 = &puStack_4fc;
            unaff_s7 = &puStack_500;
            pcStack_538 = (char *)apuStack_4f4;
            uStack_430 = 0x8000001f;
            do {
              if (local_42c[0] == (undefined *)0xffffffff) goto LAB_004712e4;
              pcVar14 = (char *)ppuStack_550;
              iVar4 = (**(code **)(puStack_518 + -0x704c))(unaff_s7);
              if (iVar4 != -1) goto LAB_0047127c;
              (**(code **)(puStack_518 + -0x53e0))(pcStack_538,0,0x80);
              iVar4 = (**(code **)(puStack_518 + -0x5338))(uStack_504);
              pcVar25 = *(code **)(puStack_518 + -0x758c);
              uStack_4f8 = 0;
              puStack_4fc = local_42c[0];
              apuStack_4f4[iVar4] =
                   (undefined *)(1 << (uStack_504 & 0x1f) | (uint)apuStack_4f4[iVar4]);
              iVar4 = (*pcVar25)(iVar2,1);
              if (iVar4 == 0) {
                iVar4 = (**(code **)(puStack_518 + -0x758c))(iVar2,2);
                if (iVar4 == 0) {
                  pcVar14 = "Unexpected retry condition\n";
                  (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
                  goto LAB_0047127c;
                }
                ppuStack_520 = ppuStack_510;
                iVar4 = (**(code **)(puStack_518 + -0x5314))(uStack_504 + 1,0,pcStack_538,0);
              }
              else {
                ppuStack_520 = ppuStack_510;
                iVar4 = (**(code **)(puStack_518 + -0x5314))(uStack_504 + 1,pcStack_538,0,0);
              }
              if (iVar4 == 0) {
                pcVar14 = "Timeout on request\n";
                (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
                goto LAB_0047127c;
              }
            } while (iVar4 != -1);
            pcVar14 = "Select error\n";
            (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
          }
LAB_0047127c:
          pcVar25 = *(code **)(puStack_518 + -0x7048);
          goto LAB_00471280;
        }
      }
    }
    else {
      (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x66,1);
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x65,0,0);
      if (0 < iVar4) {
        iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
        if (0 < iVar4) goto LAB_004710ec;
LAB_0047102c:
        pcVar14 = "Can\'t get connection fd\n";
        (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
        puStack_558 = puStack_500;
        if (puStack_500 == (undefined *)0x0) goto LAB_00471460;
        goto LAB_00471048;
      }
      iVar4 = (**(code **)(puStack_518 + -0x758c))(iVar2,8);
      if (iVar4 == 0) goto LAB_00471484;
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
      if (iVar4 < 1) goto LAB_0047102c;
      (**(code **)(puStack_518 + -0x53e0))(apuStack_4f4,0,0x80);
      iVar4 = (**(code **)(puStack_518 + -0x5338))(uStack_504);
      pcVar25 = *(code **)(puStack_518 + -0x5314);
      uStack_4f8 = 0;
      puStack_4fc = local_42c[0];
      ppuStack_520 = &puStack_4fc;
      apuStack_4f4[iVar4] = (undefined *)(1 << (uStack_504 & 0x1f) | (uint)apuStack_4f4[iVar4]);
      iVar4 = (*pcVar25)(uStack_504 + 1,0,apuStack_4f4,0);
      if (iVar4 != 0) goto LAB_004710ec;
      (**(code **)(puStack_518 + -0x7e88))(iStack_50c,"Timeout on connect\n");
    }
LAB_00471460:
    puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
    goto LAB_00471464;
  }
  uVar8 = (**(code **)(puStack_518 + -0x7470))();
  iStack_434 = (**(code **)(puStack_518 + -0x7558))(uVar8);
  if (iStack_434 != 0) {
    (**(code **)(puStack_518 + -0x7694))(iStack_434,0x21,4,0);
    uVar8 = (**(code **)(puStack_518 + -0x7044))(iStack_434,1);
    iVar2 = (**(code **)(puStack_518 + -0x7920))(uVar8,iVar2);
    goto LAB_00470fa8;
  }
  puStack_558 = (undefined *)0x0;
  pcVar14 = "Error creating SSL context.\n";
  (**(code **)(puStack_518 + -0x7fa8))(iStack_50c);
LAB_00471050:
  (**(code **)(puStack_518 + -0x7f6c))(iVar2);
LAB_00471060:
  unaff_s3 = iVar2;
  if (iStack_434 != 0) {
    (**(code **)(puStack_518 + -0x7568))(iStack_434);
  }
LAB_00471074:
  if (iStack_474 == *(int *)puStack_540) {
    return puStack_558;
  }
  pcStack_534 = ocsp_main;
  (**(code **)(puStack_518 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar15 = PTR_bio_err_006a7f3c;
  iStack_5f0 = -1;
  puStack_548 = local_42c[0];
  puStack_5f4 = &DAT_0063ba98;
  puStack_5fc = (undefined *)0x0;
  puStack_5f8 = (undefined *)0x0;
  uStack_5ec = 0;
  iStack_5e8 = 0;
  iStack_5e4 = 0;
  iStack_55c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)PTR_bio_err_006a7f3c;
  uStack_554 = uStack_430;
  iStack_54c = unaff_s3;
  iStack_544 = iStack_434;
  ppuStack_53c = unaff_s7;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar15 = iVar2;
  }
  iVar2 = load_config(iVar2,0);
  if (iVar2 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    (*(code *)PTR_SSL_library_init_006a8980)();
    uStack_684 = (*(code *)PTR_sk_new_null_006a80a4)();
    uStack_68c = (*(code *)PTR_sk_new_null_006a80a4)();
    ppuVar24 = *(undefined ***)((int)pcVar14 + 4);
    if ((ppuVar24 != (undefined **)0x0) && (*(char *)ppuVar24 == '-')) {
      iStack_6ac = 0;
      puStack_6a0 = (undefined *)0x0;
      puStack_6a4 = (undefined *)0x0;
      iStack_650 = -1;
      puVar20 = (undefined *)0x0;
      iStack_674 = -1;
      iVar2 = 0x630000;
      iStack_61c = -1;
      puStack_664 = (undefined *)0x0;
      ppuVar22 = (undefined **)0x640000;
      iStack_638 = 0;
      puVar23 = &UNK_0064492c;
      iStack_620 = 300;
      uStack_640 = 0;
      pcStack_694 = "s\n";
      uStack_63c = 0;
      uStack_654 = 0;
      pcStack_6b0 = (char *)0x0;
      puStack_628 = (undefined *)0x0;
      iStack_670 = 1;
      puStack_65c = (undefined *)0x0;
      puStack_614 = (undefined *)0x0;
      puStack_618 = (undefined *)0x0;
      iStack_648 = 0;
      pcStack_6a8 = "certificate";
      iStack_658 = 0;
      iStack_688 = 0;
      iStack_690 = 0;
      iStack_624 = 0;
      puStack_6bc = (undefined *)0x0;
      puStack_678 = (undefined *)0x0;
      puStack_66c = (undefined *)0x0;
      puStack_660 = (undefined *)0x0;
      puStack_668 = (undefined *)0x0;
      puStack_62c = (undefined *)0x0;
      puStack_6b4 = (undefined *)0x0;
      pcStack_69c = "issuer certificate";
      puStack_6b8 = (undefined *)0x0;
      unaff_s7 = (undefined **)0xffffffff;
      goto LAB_00471954;
    }
    puStack_6a0 = (undefined *)0x0;
    puStack_6a4 = (undefined *)0x0;
    puVar19 = (undefined *)0x0;
    puStack_664 = (undefined *)0x0;
    puStack_6b8 = (undefined *)0x0;
    iStack_650 = -1;
    iStack_674 = -1;
    iStack_61c = -1;
    iStack_638 = 0;
    uStack_640 = 0;
    iStack_620 = 300;
    uStack_63c = 0;
    uStack_654 = 0;
    ppuStack_634 = (undefined **)0xffffffff;
    pcStack_6b0 = (char *)0x0;
    puStack_628 = (undefined *)0x0;
    iStack_670 = 1;
    bVar1 = false;
    puStack_65c = (undefined *)0x0;
    puStack_614 = (undefined *)0x0;
    puStack_618 = (undefined *)0x0;
    iStack_648 = 0;
    iStack_658 = 0;
    iStack_688 = 0;
    iStack_690 = 0;
    iStack_624 = 0;
    puStack_6bc = (undefined *)0x0;
    puStack_678 = (undefined *)0x0;
    puStack_66c = (undefined *)0x0;
    puStack_660 = (undefined *)0x0;
    puStack_668 = (undefined *)0x0;
    puStack_62c = (undefined *)0x0;
    puStack_6b4 = (undefined *)0x0;
    unaff_s7 = ppuVar24;
    goto LAB_00471af4;
  }
  ppuVar17 = (undefined **)0x0;
  uStack_68c = 0;
  pcStack_694 = (char *)0x0;
  uStack_684 = 0;
  ppuVar22 = (undefined **)0x0;
  puStack_6b8 = (undefined *)0x0;
  puVar23 = (undefined *)0x1;
  iStack_6ac = 0;
  puVar19 = (undefined *)0x0;
  puStack_6b4 = (undefined *)0x0;
  ppuVar24 = (undefined **)0x0;
  puStack_6a4 = (undefined *)0x0;
  iVar2 = 0;
  puStack_698 = (undefined *)0x0;
  pcStack_6a8 = (char *)0x0;
  puStack_6bc = (undefined *)0x0;
  iStack_688 = 0;
  iStack_690 = 0;
LAB_00471618:
  do {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar15);
    (*(code *)PTR_X509_free_006a7f90)(puStack_6bc);
    (*(code *)PTR_X509_STORE_free_006a8384)(ppuVar24);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(puStack_698);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(puStack_6a4);
    (*(code *)PTR_X509_free_006a7f90)(iStack_690);
    (*(code *)PTR_X509_free_006a7f90)(iStack_688);
    (*(code *)PTR_X509_free_006a7f90)(pcStack_6a8);
    (*(code *)PTR_X509_free_006a7f90)(ppuVar22);
    free_index(pcStack_694);
    (*(code *)PTR_BIO_free_all_006a7f74)(iStack_5e4);
    (*(code *)PTR_BIO_free_all_006a7f74)(puStack_6b4);
    (*(code *)PTR_BIO_free_006a7f70)(iStack_6ac);
    (*(code *)PTR_OCSP_REQUEST_free_006a8864)(iStack_5e8);
    (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(ppuVar17);
    (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(iVar2);
    (*(code *)PTR_sk_free_006a7f80)(uStack_684);
    (*(code *)PTR_sk_free_006a7f80)(uStack_68c);
    (*(code *)PTR_sk_pop_free_006a8158)(puStack_6b8,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar19,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(uStack_5ec,PTR_X509V3_conf_free_006a8c38);
    if (iStack_5f0 != -1) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_5fc);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_5f8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_5f4);
    }
    if (iStack_55c == *(int *)puVar3) {
      return puVar23;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004736bc:
    iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_cert_checks");
    if (iVar4 == 0) {
      uStack_63c = uStack_63c | 0x100;
      bVar1 = false;
    }
    else {
      iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_explicit");
      if (iVar4 == 0) {
        uStack_63c = uStack_63c | 0x20;
        bVar1 = false;
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-trust_other");
        if (iVar4 == 0) {
          uStack_63c = uStack_63c | 0x200;
          bVar1 = false;
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_intern");
          if (iVar4 == 0) {
            uStack_63c = uStack_63c | 2;
            bVar1 = false;
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-text");
            if (iVar4 == 0) {
              bVar1 = false;
              iStack_648 = 1;
              iStack_658 = 1;
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-req_text");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_658 = 1;
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_text");
                if (iVar4 == 0) {
                  bVar1 = false;
                  iStack_648 = 1;
                }
                else {
                  iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-reqin");
                  puVar20 = puVar19;
                  if (iVar4 == 0) {
                    ppuVar24 = ppuVar17 + 1;
                    if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                    bVar1 = false;
                    ppuVar17 = ppuVar17 + 1;
                    puStack_6b4 = *ppuVar24;
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-respin");
                    if (iVar4 == 0) {
                      ppuVar24 = ppuVar17 + 1;
                      if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                      bVar1 = false;
                      ppuVar17 = ppuVar17 + 1;
                      puStack_62c = *ppuVar24;
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-signer");
                      if (iVar4 == 0) {
                        ppuVar24 = ppuVar17 + 1;
                        if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                        bVar1 = false;
                        ppuVar17 = ppuVar17 + 1;
                        puStack_66c = *ppuVar24;
                      }
                      else {
                        iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-VAfile");
                        if (iVar4 == 0) {
                          ppuVar24 = ppuVar17 + 1;
                          if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                          bVar1 = false;
                          uStack_63c = uStack_63c | 0x200;
                          ppuVar17 = ppuVar17 + 1;
                          puStack_628 = *ppuVar24;
                        }
                        else {
                          iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-sign_other");
                          if (iVar4 == 0) {
                            ppuVar24 = ppuVar17 + 1;
                            if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                            bVar1 = false;
                            ppuVar17 = ppuVar17 + 1;
                            puStack_65c = *ppuVar24;
                          }
                          else {
                            iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-verify_other");
                            if (iVar4 == 0) {
                              ppuVar24 = ppuVar17 + 1;
                              if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                              bVar1 = false;
                              ppuVar17 = ppuVar17 + 1;
                              puStack_628 = *ppuVar24;
                            }
                            else {
                              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-CAfile");
                              if (iVar4 == 0) {
                                ppuVar24 = ppuVar17 + 1;
                                if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                bVar1 = false;
                                ppuVar17 = ppuVar17 + 1;
                                puStack_618 = *ppuVar24;
                              }
                              else {
                                iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-CApath");
                                if (iVar4 == 0) {
                                  ppuVar24 = ppuVar17 + 1;
                                  if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                  bVar1 = false;
                                  ppuVar17 = ppuVar17 + 1;
                                  puStack_614 = *ppuVar24;
                                }
                                else {
                                  iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                    (ppuVar24,"-validity_period");
                                  if (iVar4 == 0) {
                                    if (ppuVar17[1] == (undefined *)0x0) goto LAB_00471a70;
                                    ppuVar24 = ppuVar17 + 1;
                                    iStack_620 = (*(code *)PTR_strtol_006aaa68)(ppuVar17[1],0,10);
                                    if (-1 < iStack_620) goto LAB_004719ac;
                                    (*(code *)PTR_BIO_printf_006a7f38)
                                              (*(undefined4 *)puVar15,"Illegal validity period %s\n"
                                               ,ppuVar17[1]);
                                    bVar1 = true;
                                    ppuVar17 = ppuVar24;
                                  }
                                  else {
                                    iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-status_age");
                                    if (iVar4 == 0) {
                                      if (ppuVar17[1] == (undefined *)0x0) goto LAB_00471a70;
                                      ppuVar24 = ppuVar17 + 1;
                                      iStack_61c = (*(code *)PTR_strtol_006aaa68)(ppuVar17[1],0,10);
                                      if (-1 < iStack_61c) goto LAB_004719ac;
                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                (*(undefined4 *)puVar15,"Illegal validity age %s\n",
                                                 ppuVar17[1]);
                                      bVar1 = true;
                                      ppuVar17 = ppuVar24;
                                    }
                                    else {
                                      iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-signkey");
                                      if (iVar4 == 0) {
                                        ppuVar24 = ppuVar17 + 1;
                                        if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                        bVar1 = false;
                                        ppuVar17 = ppuVar17 + 1;
                                        puStack_678 = *ppuVar24;
                                      }
                                      else {
                                        iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-reqout");
                                        if (iVar4 == 0) {
                                          ppuVar24 = ppuVar17 + 1;
                                          if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                          bVar1 = false;
                                          ppuVar17 = ppuVar17 + 1;
                                          puStack_668 = *ppuVar24;
                                        }
                                        else {
                                          iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                            (ppuVar24,"-respout");
                                          if (iVar4 == 0) {
                                            ppuVar24 = ppuVar17 + 1;
                                            if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                            bVar1 = false;
                                            ppuVar17 = ppuVar17 + 1;
                                            puStack_660 = *ppuVar24;
                                          }
                                          else {
                                            iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-path")
                                            ;
                                            if (iVar4 == 0) {
                                              ppuVar24 = ppuVar17 + 1;
                                              if (*ppuVar24 == (undefined *)0x0) goto LAB_00471a70;
                                              bVar1 = false;
                                              ppuVar17 = ppuVar17 + 1;
                                              puStack_5f4 = *ppuVar24;
                                            }
                                            else {
                                              iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                (ppuVar24,"-issuer");
                                              if (iVar4 != 0) {
                                                iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                  (ppuVar24,"-cert");
                                                if (iVar4 == 0) {
                                                  if (ppuVar17[1] == (undefined *)0x0)
                                                  goto LAB_00471a70;
                                                  (*(code *)PTR_X509_free_006a7f90)(iStack_688);
                                                  iStack_688 = load_cert(*(undefined4 *)puVar15,
                                                                         ppuVar17[1],3,0,0,
                                                                         pcStack_6a8);
                                                  if (iStack_688 == 0) goto LAB_00472a0c;
                                                  if (iStack_6ac == 0) {
                                                    iStack_6ac = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                  }
                                                  if (iStack_690 == 0) {
LAB_00473d18:
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar15,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00472a0c;
                                                  }
                                                  if ((iStack_5e8 != 0) ||
                                                     (iStack_5e8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), iStack_5e8 != 0)
                                                  ) {
                                                    iVar6 = (*(code *)PTR_OCSP_cert_to_id_006a8870)
                                                                      (iStack_6ac,iStack_688,
                                                                       iStack_690);
joined_r0x00473e14:
                                                    if (iVar6 != 0) {
                                                      iVar4 = (*(code *)PTR_sk_push_006a80a8)
                                                                        (uStack_68c,iVar6);
                                                      if ((iVar4 != 0) &&
                                                         (iVar4 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a8874)
                                                            (iStack_5e8,iVar6), iVar4 != 0)) {
                                                    iVar4 = (*(code *)PTR_sk_push_006a80a8)
                                                                      (uStack_684,ppuVar17[1]);
                                                    if (iVar4 != 0) {
                                                      bVar1 = false;
                                                      ppuVar17 = ppuVar17 + 1;
                                                      goto LAB_00471934;
                                                    }
                                                    goto LAB_00472a0c;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                    (ppuVar24,"-serial");
                                                  if (iVar4 != 0) {
                                                    iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                      (ppuVar24,"-index");
                                                    if (iVar4 == 0) {
                                                      ppuVar24 = ppuVar17 + 1;
                                                      if (*ppuVar24 == (undefined *)0x0)
                                                      goto LAB_00471a70;
                                                      bVar1 = false;
                                                      ppuVar17 = ppuVar17 + 1;
                                                      puStack_664 = *ppuVar24;
                                                    }
                                                    else if (((*(char *)((int)ppuVar24 + 1) == 'C')
                                                             && (*(char *)((int)ppuVar24 + 2) == 'A'
                                                                )) && (*(char *)((int)ppuVar24 + 3)
                                                                       == '\0')) {
                                                      ppuVar24 = ppuVar17 + 1;
                                                      if (*ppuVar24 == (undefined *)0x0)
                                                      goto LAB_00471a70;
                                                      bVar1 = false;
                                                      ppuVar17 = ppuVar17 + 1;
                                                      puStack_6a4 = *ppuVar24;
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                        (ppuVar24,"-nmin");
                                                      if (iVar4 == 0) {
                                                        if (ppuVar17[1] == (undefined *)0x0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          puStack_6a0 = (undefined *)
                                                                        (*(code *)
                                                  PTR_strtol_006aaa68)(ppuVar17[1],0,10);
                                                  if ((int)puStack_6a0 < 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar15,
                                                               "Illegal update period %s\n",
                                                               ppuVar17[1]);
                                                    bVar1 = true;
                                                    ppuVar17 = ppuVar17 + 1;
                                                  }
                                                  else {
                                                    bVar1 = false;
                                                    ppuVar17 = ppuVar17 + 1;
                                                  }
                                                  }
                                                  if (iStack_650 != -1) goto LAB_00471a70;
                                                  iStack_650 = 0;
                                                  }
                                                  else {
                                                    iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                      (ppuVar24,"-nrequest");
                                                    if (iVar4 == 0) {
                                                      if (ppuVar17[1] == (undefined *)0x0)
                                                      goto LAB_00471a70;
                                                      ppuVar24 = ppuVar17 + 1;
                                                      iStack_674 = (*(code *)PTR_strtol_006aaa68)
                                                                             (ppuVar17[1],0,10);
                                                      if (-1 < iStack_674) goto LAB_004719ac;
                                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                                (*(undefined4 *)puVar15,
                                                                 "Illegal accept count %s\n",
                                                                 ppuVar17[1]);
                                                      bVar1 = true;
                                                      ppuVar17 = ppuVar24;
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                        (ppuVar24,"-ndays");
                                                      if (iVar4 == 0) {
                                                        if (ppuVar17[1] == (undefined *)0x0)
                                                        goto LAB_00471a70;
                                                        ppuVar24 = ppuVar17 + 1;
                                                        iStack_650 = (*(code *)PTR_strtol_006aaa68)
                                                                               (ppuVar17[1],0,10);
                                                        if (-1 < iStack_650) goto LAB_004719ac;
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar15,
                                                                   "Illegal update period %s\n",
                                                                   ppuVar17[1]);
                                                        bVar1 = true;
                                                        ppuVar17 = ppuVar24;
                                                      }
                                                      else {
                                                        iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                          (ppuVar24,"-rsigner");
                                                        if (iVar4 == 0) {
                                                          ppuVar24 = ppuVar17 + 1;
                                                          if (*ppuVar24 == (undefined *)0x0)
                                                          goto LAB_00471a70;
                                                          ppuVar17 = ppuVar17 + 1;
                                                          bVar1 = false;
                                                          puStack_6bc = *ppuVar24;
                                                        }
                                                        else {
                                                          iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                            (ppuVar24,"-rkey");
                                                          if (iVar4 == 0) {
                                                            ppuVar24 = ppuVar17 + 1;
                                                            if (*ppuVar24 == (undefined *)0x0)
                                                            goto LAB_00471a70;
                                                            ppuVar17 = ppuVar17 + 1;
                                                            bVar1 = false;
                                                            puStack_6b8 = *ppuVar24;
                                                          }
                                                          else {
                                                            iVar4 = (*(code *)PTR_strcmp_006aac20)
                                                                              (ppuVar24,"-rother");
                                                            if (iVar4 == 0) {
                                                              ppcVar7 = ppuVar17 + 1;
                                                              if (*ppcVar7 == (char *)0x0) {
                                                                bVar1 = true;
                                                              }
                                                              else {
                                                                ppuVar17 = ppuVar17 + 1;
                                                                bVar1 = false;
                                                                pcStack_6b0 = *ppcVar7;
                                                              }
                                                            }
                                                            else {
                                                              iStack_6ac = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)
                                                            ((char *)((int)ppuVar24 + 1));
                                                  bVar1 = iStack_6ac == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00471934;
                                                  }
                                                  puStack_698 = ppuVar17[1];
                                                  if (puStack_698 == (undefined *)0x0)
                                                  goto LAB_00471a70;
                                                  if (iStack_6ac == 0) {
                                                    iStack_6ac = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                    puStack_698 = ppuVar17[1];
                                                  }
                                                  if (iStack_690 == 0) goto LAB_00473d18;
                                                  if ((iStack_5e8 != 0) ||
                                                     (iStack_5e8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), iStack_5e8 != 0)
                                                  ) {
                                                    uVar8 = (*(code *)
                                                  PTR_X509_get_subject_name_006a8000)(iStack_690);
                                                  uVar9 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a8f18)(iStack_690);
                                                  iVar4 = (*(code *)PTR_s2i_ASN1_INTEGER_006a80b4)
                                                                    (0,puStack_698);
                                                  if (iVar4 != 0) {
                                                    iVar6 = (*(code *)PTR_OCSP_cert_id_new_006a8f1c)
                                                                      (iStack_6ac,uVar8,uVar9,iVar4)
                                                    ;
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4)
                                                    ;
                                                    goto joined_r0x00473e14;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar15,
                                                             "Error converting serial number %s\n",
                                                             puStack_698);
                                                  goto LAB_00472a0c;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a7f38)
                                                          (*(undefined4 *)puVar15,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00472a0c;
                                              }
                                              if (ppuVar17[1] == (undefined *)0x0)
                                              goto LAB_00471a70;
                                              (*(code *)PTR_X509_free_006a7f90)(iStack_690);
                                              iStack_690 = load_cert(*(undefined4 *)puVar15,
                                                                     ppuVar17[1],3,0,0,pcStack_69c);
                                              if (iStack_690 == 0) goto LAB_00472a0c;
                                              bVar1 = false;
                                              ppuVar17 = ppuVar17 + 1;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00471934:
    ppuStack_634 = unaff_s7;
    if (!bVar1) {
      ppuVar24 = (undefined **)ppuVar17[1];
      if ((ppuVar24 == (undefined **)0x0) ||
         (puVar20 = puVar19, pcVar14 = (char *)ppuVar17, *(char *)ppuVar24 != '-'))
      goto LAB_00471af4;
LAB_00471954:
      ppuVar17 = (undefined **)((int)pcVar14 + 4);
      iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,iVar2 + 0x2edc);
      if (iVar4 == 0) {
        puVar19 = *(undefined **)((int)pcVar14 + 8);
        if (puVar19 != (undefined *)0x0) {
          bVar1 = false;
          ppuVar17 = (undefined **)((int)pcVar14 + 8);
          goto LAB_00471934;
        }
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,ppuVar22 + -0xfdc);
        puVar19 = puVar20;
        if (iVar4 == 0) {
          if (*(undefined **)((int)pcVar14 + 8) == (undefined *)0x0) goto LAB_00471a70;
          ppuVar24 = (undefined **)((int)pcVar14 + 8);
          unaff_s7 = (undefined **)
                     (*(code *)PTR_strtol_006aaa68)(*(undefined **)((int)pcVar14 + 8),0,10);
          if (-1 < (int)unaff_s7) goto LAB_004719ac;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar15,"Illegal timeout value %s\n",
                     *(undefined **)((int)pcVar14 + 8));
          bVar1 = true;
          ppuVar17 = ppuVar24;
          goto LAB_00471934;
        }
        iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,puVar23);
        if (iVar4 == 0) {
          if (*(undefined **)((int)pcVar14 + 8) != (undefined *)0x0) {
            ppuVar24 = (undefined **)((int)pcVar14 + 8);
            iVar4 = (*(code *)PTR_OCSP_parse_url_006a8854)
                              (*(undefined **)((int)pcVar14 + 8),&puStack_5fc,&puStack_5f8,
                               &puStack_5f4,&iStack_5f0);
            if (iVar4 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"Error parsing URL\n");
              bVar1 = true;
              ppuVar17 = ppuVar24;
            }
            else {
LAB_004719ac:
              bVar1 = false;
              ppuVar17 = ppuVar24;
            }
            goto LAB_00471934;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,pcStack_694 + -0x26dc);
          if (iVar4 == 0) {
            if (*(undefined **)((int)pcVar14 + 8) != (undefined *)0x0) {
              bVar1 = false;
              ppuVar17 = (undefined **)((int)pcVar14 + 8);
              puStack_5fc = *(undefined **)((int)pcVar14 + 8);
              goto LAB_00471934;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-port");
            if (iVar4 == 0) {
              if (*(undefined **)((int)pcVar14 + 8) == (undefined *)0x0) goto LAB_00471a70;
              bVar1 = false;
              ppuVar17 = (undefined **)((int)pcVar14 + 8);
              puStack_5f8 = *(undefined **)((int)pcVar14 + 8);
              goto LAB_00471934;
            }
            iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-header");
            if (iVar4 != 0) {
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-ignore_err");
              if (iVar4 == 0) {
                iStack_638 = 1;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-noverify");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_624 = 1;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-nonce");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_670 = 2;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_nonce");
              if (iVar4 == 0) {
                iStack_670 = 0;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_no_certs");
              if (iVar4 == 0) {
                uStack_640 = uStack_640 | 1;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_key_id");
              if (iVar4 == 0) {
                uStack_640 = uStack_640 | 0x400;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_certs");
              if (iVar4 == 0) {
                bVar1 = false;
                uStack_654 = 1;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_signature_verify");
              if (iVar4 == 0) {
                uStack_63c = uStack_63c | 4;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_cert_verify");
              if (iVar4 == 0) {
                uStack_63c = uStack_63c | 0x10;
                bVar1 = false;
                goto LAB_00471934;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_chain");
              if (iVar4 == 0) {
                uStack_63c = uStack_63c | 8;
                bVar1 = false;
                goto LAB_00471934;
              }
              goto LAB_004736bc;
            }
            if ((*(undefined **)((int)pcVar14 + 8) != (undefined *)0x0) &&
               (*(undefined **)((int)pcVar14 + 0xc) != (undefined *)0x0)) {
              iVar4 = (*(code *)PTR_X509V3_add_value_006a8ea4)
                                (*(undefined **)((int)pcVar14 + 8),
                                 *(undefined **)((int)pcVar14 + 0xc),&uStack_5ec);
              if (iVar4 == 0) goto LAB_00472a0c;
              bVar1 = false;
              ppuVar17 = (undefined **)((int)pcVar14 + 0xc);
              goto LAB_00471934;
            }
          }
        }
      }
LAB_00471a70:
      bVar1 = true;
      puVar19 = puVar20;
      goto LAB_00471934;
    }
    bVar1 = true;
LAB_00471af4:
    if (((((iStack_5e8 == 0) && (puStack_6b4 == (undefined *)0x0)) &&
         (puStack_62c == (undefined *)0x0)) &&
        ((puStack_5f8 == (undefined *)0x0 || (puStack_664 == (undefined *)0x0)))) || (bVar1)) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"OCSP utility\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"Usage ocsp [options]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"where options are\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-out file          output filename\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-issuer file       issuer certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-cert file         certificate to check\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-serial n          serial number to check\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-signer file       certificate to sign OCSP request with\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-signkey file      private key to sign OCSP request with\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-sign_other file   additional certificates to include in signed request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-no_certs          don\'t include any certificates in signed request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-req_text          print text form of request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-resp_text         print text form of response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-text              print text form of request and response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-reqout file       write DER encoded OCSP request to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-respout file      write DER encoded OCSP reponse to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-reqin file        read DER encoded OCSP request from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-respin file       read DER encoded OCSP reponse from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-nonce             add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-no_nonce          don\'t add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-url URL           OCSP responder URL\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-host host:n       send OCSP request to host on port n\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-path              path to use in OCSP request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-CApath dir        trusted certificates directory\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-CAfile file       trusted certificates file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-VAfile file       validator certificates file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-validity_period n maximum validity discrepancy in seconds\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-status_age n      maximum status age in seconds\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-noverify          don\'t verify response at all\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-verify_other file additional certificates to search for signer\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-trust_other       don\'t verify additional certificates\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-no_intern         don\'t search certificates contained in response for signer\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-no_signature_verify don\'t check signature on response\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-no_cert_verify    don\'t check signing certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-no_chain          don\'t chain verify response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-no_cert_checks    don\'t do additional checks on signing certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-port num\t\t port to run responder on\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-index file\t certificate status index file\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"-CA file\t\t CA certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-rsigner file\t responder certificate to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-rkey file\t responder key to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-rother file\t other certificates to include in response\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-resp_no_certs     don\'t include any certificates in response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-nmin n\t \t number of minutes before next update\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-ndays n\t \t number of days before next update\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-resp_key_id       identify reponse by signing certificate key ID\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,
                 "-nrequest n        number of requests to accept (default unlimited)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar15,"-<dgst alg>     use specified digest in the request\n");
LAB_00472a0c:
      ppuVar17 = (undefined **)0x0;
      iStack_6ac = 0;
    }
    else {
      if (puVar19 == (undefined *)0x0) {
        iStack_6ac = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
      }
      else {
        iStack_6ac = (*(code *)PTR_BIO_new_file_006a7fac)(puVar19,"w");
      }
      puVar20 = puStack_5f8;
      if (iStack_6ac == 0) {
        ppuVar17 = (undefined **)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar15,"Error opening output file\n");
      }
      else {
        if (iStack_5e8 != 0) {
LAB_00471b38:
          puStack_6b4 = (undefined *)0x0;
          if (puStack_6bc == (undefined *)0x0) {
            ppuVar22 = (undefined **)0x0;
            iStack_610 = 0;
            puStack_6a4 = (undefined *)0x0;
            pcStack_6a8 = (char *)0x0;
          }
          else {
LAB_00471b44:
            puVar20 = PTR_bio_err_006a7f3c;
            puVar23 = puStack_6bc;
            if (puStack_6b8 != (undefined *)0x0) {
              puVar23 = puStack_6b8;
            }
            pcStack_6a8 = (char *)load_cert(*(undefined4 *)puVar15,puStack_6bc,3,0,0,
                                            "responder certificate");
            if (pcStack_6a8 == (char *)0x0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar20,"Error loading responder certificate\n");
              ppuVar22 = (undefined **)0x0;
LAB_00472e8c:
              pcStack_694 = (char *)0x0;
              ppuVar17 = (undefined **)0x0;
              puVar23 = (undefined *)0x1;
              puStack_6b8 = (undefined *)0x0;
              puVar19 = (undefined *)0x0;
              puStack_6a4 = (undefined *)0x0;
              ppuVar24 = (undefined **)0x0;
              puStack_698 = (undefined *)0x0;
              puStack_6bc = (undefined *)0x0;
              iVar2 = 0;
              goto LAB_00471618;
            }
            ppuVar22 = (undefined **)
                       load_cert(*(undefined4 *)puVar20,puStack_6a4,3,0,0,"CA certificate");
            if (pcStack_6b0 == (char *)0x0) {
              iStack_610 = 0;
            }
            else {
              iStack_610 = load_certs(*(undefined4 *)puVar20,pcStack_6b0,3,0,0,
                                      "responder other certificates");
              if (iStack_610 == 0) goto LAB_00472e8c;
            }
            puStack_6a4 = (undefined *)
                          load_key(*(undefined4 *)puVar15,puVar23,3,0,0,0,"responder private key");
            if (puStack_6a4 == (undefined *)0x0) {
              ppuVar17 = (undefined **)0x0;
              puStack_6b8 = (undefined *)0x0;
              pcStack_694 = (char *)0x0;
              puStack_698 = (undefined *)0x0;
              puVar23 = (undefined *)0x1;
              puStack_6bc = (undefined *)0x0;
              puVar19 = (undefined *)0x0;
              ppuVar24 = (undefined **)0x0;
              iVar2 = 0;
              goto LAB_00471618;
            }
            if (puStack_6b4 != (undefined *)0x0) {
LAB_00471c34:
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar15,"Waiting for OCSP client connections...\n");
            }
          }
          puStack_6b8 = (undefined *)0x0;
          puStack_698 = (undefined *)0x0;
          puStack_6bc = (undefined *)0x0;
          pcStack_694 = (char *)0x0;
          iVar4 = (int)puStack_6a0 * 0x3c;
          ppuVar17 = (undefined **)0x0;
LAB_00471cc4:
          do {
            unaff_s7 = ppuVar22;
            if (puStack_6b4 != (undefined *)0x0) {
              iVar2 = do_responder_isra_0(&iStack_5e8,&iStack_5e4,puStack_6b4);
              if (iVar2 != 0) {
                if (iStack_5e8 != 0) goto LAB_00471cf4;
                ppuVar17 = (undefined **)(*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
                puVar5 = auStack_5b0;
                puVar13 = (undefined4 *)
                          "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
                ;
                do {
                  puVar12 = puVar13 + 4;
                  puVar11 = puVar5 + 4;
                  uVar16 = puVar13[1];
                  uVar9 = puVar13[2];
                  uVar8 = puVar13[3];
                  *puVar5 = *puVar13;
                  puVar5[1] = uVar16;
                  puVar5[2] = uVar9;
                  puVar5[3] = uVar8;
                  puVar5 = puVar11;
                  puVar13 = puVar12;
                } while (puVar12 != (undefined4 *)0x645930);
                *(char *)puVar11 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
                if (iStack_5e4 == 0) goto LAB_004722fc;
LAB_004721ec:
                iVar2 = iStack_5e4;
                uVar8 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a8884)(ppuVar17,0);
                (*(code *)PTR_BIO_printf_006a7f38)(iVar2,auStack_5b0,uVar8);
                (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar2,ppuVar17);
                (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0xb,0,0);
                goto LAB_004722fc;
              }
LAB_00472c58:
              puVar23 = (undefined *)0x1;
              puVar19 = (undefined *)0x0;
              ppuVar24 = (undefined **)0x0;
              iVar2 = 0;
              goto LAB_00471618;
            }
            if (iStack_5e8 != 0) {
LAB_00471cf4:
              if (iStack_670 != 0) {
                (*(code *)PTR_OCSP_request_add1_nonce_006a8eac)(iStack_5e8,0,0xffffffff);
              }
              puVar20 = PTR_bio_err_006a7f3c;
              if (puStack_66c != (undefined *)0x0) {
                puStack_6bc = (undefined *)
                              load_cert(*(undefined4 *)puVar15,puStack_66c,3,0,0,
                                        "signer certificate");
                if (puStack_678 == (undefined *)0x0) {
                  puStack_678 = puStack_66c;
                }
                if (puStack_6bc == (undefined *)0x0) {
                  uVar8 = *(undefined4 *)puVar20;
                  pcVar14 = "Error loading signer certificate\n";
                }
                else {
                  if (((puStack_65c != (undefined *)0x0) &&
                      (puStack_6b8 = (undefined *)
                                     load_certs(*(undefined4 *)puVar20,puStack_65c,3,0,0,
                                                "signer certificates"),
                      puStack_6b8 == (undefined *)0x0)) ||
                     (puStack_698 = (undefined *)
                                    load_key(*(undefined4 *)puVar15,puStack_678,3,0,0,0,
                                             "signer private key"), puStack_698 == (undefined *)0x0)
                     ) goto LAB_00472c58;
                  iVar2 = (*(code *)PTR_OCSP_request_sign_006a8eb0)
                                    (iStack_5e8,puStack_6bc,puStack_698,0,puStack_6b8,uStack_654);
                  if (iVar2 != 0) goto LAB_00471dec;
                  pcVar14 = "Error signing OCSP request\n";
                  uVar8 = *(undefined4 *)PTR_bio_err_006a7f3c;
                }
                goto LAB_00472c0c;
              }
LAB_00471dec:
              if ((iStack_658 != 0) && (iStack_5e8 != 0)) {
                (*(code *)PTR_OCSP_REQUEST_print_006a8eb4)(iStack_6ac,iStack_5e8,0);
              }
              if (puStack_668 == (undefined *)0x0) {
LAB_00471e64:
                if (puStack_664 == (undefined *)0x0) goto LAB_004722b0;
                if (((puStack_6a4 == (undefined *)0x0) || (pcStack_6a8 == (char *)0x0)) ||
                   (ppuVar22 == (undefined **)0x0)) {
                  uVar8 = *(undefined4 *)puVar15;
                  pcVar14 = "Need a responder certificate, key and CA for this operation!\n";
                  goto LAB_00472c0c;
                }
                if ((pcStack_694 == (char *)0x0) &&
                   ((pcStack_694 = (char *)load_index(puStack_664,0), pcStack_694 == (char *)0x0 ||
                    (iVar2 = index_index(pcStack_694), iVar2 == 0)))) goto LAB_00472c58;
                goto LAB_00471e90;
              }
              iVar2 = (*(code *)PTR_BIO_new_file_006a7fac)(puStack_668,&DAT_00632de8);
              if (iVar2 != 0) {
                (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_REQUEST_006a8eb8,iVar2,iStack_5e8)
                ;
                (*(code *)PTR_BIO_free_006a7f70)(iVar2);
                goto LAB_00471e64;
              }
              uVar8 = *(undefined4 *)puVar15;
              puVar20 = puStack_668;
LAB_00472fcc:
              puVar23 = (undefined *)0x1;
              puVar19 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar8,"Error opening file %s\n",puVar20);
              ppuVar24 = (undefined **)0x0;
              goto LAB_00471618;
            }
            if (((puStack_66c != (undefined *)0x0) || (puStack_668 != (undefined *)0x0)) ||
               ((puStack_5fc != (undefined *)0x0 ||
                ((iStack_670 != 0 || (puStack_664 != (undefined *)0x0)))))) {
              uVar8 = *(undefined4 *)puVar15;
              pcVar14 = "Need an OCSP request for this operation!\n";
LAB_00472c0c:
              puVar23 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar8,pcVar14);
              puVar19 = (undefined *)0x0;
              ppuVar24 = (undefined **)0x0;
              iVar2 = 0;
              goto LAB_00471618;
            }
LAB_004722b0:
            if (pcStack_694 == (char *)0x0) {
              if (puStack_5fc != (undefined *)0x0) {
                ppuVar17 = (undefined **)
                           process_responder(*(undefined4 *)puVar15,iStack_5e8,puStack_5fc,
                                             puStack_5f4,puStack_5f8,iStack_5f0,uStack_5ec,
                                             ppuStack_634);
                if (ppuVar17 == (undefined **)0x0) goto LAB_00472c58;
                goto LAB_004722fc;
              }
              if (puStack_62c != (undefined *)0x0) {
                iVar2 = (*(code *)PTR_BIO_new_file_006a7fac)(puStack_62c,&DAT_006347ac);
                if (iVar2 != 0) {
                  ppuVar17 = (undefined **)
                             (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                       (PTR_OCSP_RESPONSE_new_006a8ef0,
                                        PTR_d2i_OCSP_RESPONSE_006a8a28,iVar2,0);
                  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
                  if (ppuVar17 == (undefined **)0x0) {
                    uVar8 = *(undefined4 *)puVar15;
                    pcVar14 = "Error reading OCSP response\n";
                    goto LAB_00472c0c;
                  }
                  goto LAB_004722fc;
                }
                puVar23 = (undefined *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar15,"Error Opening OCSP response file\n");
                puVar19 = (undefined *)0x0;
                ppuVar24 = (undefined **)0x0;
                goto LAB_00471618;
              }
              break;
            }
LAB_00471e90:
            iVar2 = iStack_5e8;
            iVar6 = (*(code *)PTR_OCSP_request_onereq_count_006a8ebc)(iStack_5e8);
            if (iVar6 < 1) {
              iVar21 = 0;
              ppuVar17 = (undefined **)(*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
              pcStack_6b0 = (char *)0x0;
              pcStack_69c = (char *)0x0;
              puStack_6a0 = (undefined *)0x0;
            }
            else {
              pcStack_6b0 = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a8ec0)();
              puStack_6a0 = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
              if (iStack_650 == -1) {
                pcStack_69c = (char *)0x0;
              }
              else {
                pcStack_69c = (char *)(*(code *)PTR_X509_gmtime_adj_006a808c)
                                                (0,iStack_650 * 0x15180 + iVar4);
              }
              iVar21 = 0;
              iVar18 = 0;
              do {
                while( true ) {
                  uVar8 = (*(code *)PTR_OCSP_request_onereq_get0_006a8ecc)(iVar2,iVar18);
                  uVar8 = (*(code *)PTR_OCSP_onereq_get0_id_006a8ed0)(uVar8);
                  (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,&iStack_5dc,0,0,uVar8);
                  uVar9 = (*(code *)PTR_OBJ_obj2nid_006a822c)(iStack_5dc);
                  uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar9);
                  iVar10 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar9);
                  if (iVar10 == 0) {
                    ppuVar17 = (undefined **)(*(code *)PTR_OCSP_response_create_006a8ea8)(2,0);
                    goto LAB_00472150;
                  }
                  if (iVar21 != 0) {
                    (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar21);
                  }
                  iVar21 = (*(code *)PTR_OCSP_cert_to_id_006a8870)(iVar10,0,ppuVar22);
                  iVar10 = (*(code *)PTR_OCSP_id_issuer_cmp_006a8ed4)(iVar21,uVar8);
                  if (iVar10 == 0) break;
LAB_004720bc:
                  uVar9 = 2;
LAB_004720c8:
                  iVar18 = iVar18 + 1;
                  (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                            (pcStack_6b0,uVar8,uVar9,0,0,puStack_6a0,pcStack_69c);
                  if (iVar6 == iVar18) goto LAB_004720f4;
                }
                (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,0,0,&uStack_5e0,uVar8);
                uStack_5c8 = 0;
                uStack_5c4 = 0;
                uStack_5c0 = 0;
                uStack_5bc = 0;
                uStack_5b8 = 0;
                uStack_5b4 = 0;
                iVar10 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(uStack_5e0,0);
                if (iVar10 == 0) {
                  (*(code *)PTR_OpenSSLDie_006a8d4c)("ocsp.c",0x48d,&DAT_00645760);
                }
                if (*(int *)(iVar10 + 4) == 0) {
                  uVar9 = (*(code *)PTR_BUF_strdup_006a80dc)("00");
                }
                else {
                  uVar9 = (*(code *)PTR_BN_bn2hex_006a8118)(iVar10);
                }
                uStack_5bc = uVar9;
                (*(code *)PTR_BN_free_006a811c)(iVar10);
                ppcVar7 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)
                                             (*(undefined4 *)(pcStack_694 + 4),3,&uStack_5c8);
                (*(code *)PTR_CRYPTO_free_006a7f88)(uVar9);
                if (ppcVar7 == (char **)0x0) goto LAB_004720bc;
                if (**ppcVar7 == 'V') {
                  uVar9 = 0;
                  goto LAB_004720c8;
                }
                if (**ppcVar7 == 'R') {
                  iStack_5d8 = 0;
                  uStack_5d4 = 0;
                  iStack_5d0 = 0;
                  iStack_5cc = -1;
                  (*(code *)PTR_unpack_revinfo_006a8ec8)
                            (&uStack_5d4,&iStack_5cc,&iStack_5d8,&iStack_5d0,ppcVar7[2]);
                  uVar8 = (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                                    (pcStack_6b0,uVar8,1,iStack_5cc,uStack_5d4,puStack_6a0,
                                     pcStack_69c);
                  if (iStack_5d0 == 0) {
                    if (iStack_5d8 != 0) {
                      (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)
                                (uVar8,0x1ae,iStack_5d8,0,0);
                    }
                  }
                  else {
                    (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)(uVar8,0x8e,iStack_5d0,0,0);
                  }
                  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iStack_5d8);
                  (*(code *)PTR_ASN1_TIME_free_006a8150)(uStack_5d4);
                  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iStack_5d0);
                }
                iVar18 = iVar18 + 1;
              } while (iVar6 != iVar18);
LAB_004720f4:
              (*(code *)PTR_OCSP_copy_nonce_006a8edc)(pcStack_6b0,iVar2);
              (*(code *)PTR_OCSP_basic_sign_006a8ee0)
                        (pcStack_6b0,pcStack_6a8,puStack_6a4,0,iStack_610,uStack_640);
              ppuVar17 = (undefined **)(*(code *)PTR_OCSP_response_create_006a8ea8)(0,pcStack_6b0);
            }
LAB_00472150:
            (*(code *)PTR_ASN1_TIME_free_006a8150)(puStack_6a0);
            (*(code *)PTR_ASN1_TIME_free_006a8150)(pcStack_69c);
            (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar21);
            (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(pcStack_6b0);
            if (iStack_5e4 != 0) {
              puVar5 = (undefined4 *)
                       "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
              ;
              puVar13 = auStack_5b0;
              do {
                puVar11 = puVar5 + 4;
                puVar12 = puVar13 + 4;
                uVar16 = puVar5[1];
                uVar9 = puVar5[2];
                uVar8 = puVar5[3];
                *puVar13 = *puVar5;
                puVar13[1] = uVar16;
                puVar13[2] = uVar9;
                puVar13[3] = uVar8;
                puVar5 = puVar11;
                puVar13 = puVar12;
              } while (puVar11 != (undefined4 *)0x645930);
              *(char *)puVar12 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
              goto LAB_004721ec;
            }
LAB_004722fc:
            if (puStack_660 != (undefined *)0x0) {
              iVar2 = (*(code *)PTR_BIO_new_file_006a7fac)(puStack_660,&DAT_00632de8);
              if (iVar2 == 0) {
                uVar8 = *(undefined4 *)puVar15;
                puVar20 = puStack_660;
                goto LAB_00472fcc;
              }
              (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar2,ppuVar17);
              (*(code *)PTR_BIO_free_006a7f70)(iVar2);
            }
            iVar2 = (*(code *)PTR_OCSP_response_status_006a8ee4)(ppuVar17);
            if (iVar2 == 0) {
              if (iStack_648 != 0) {
                (*(code *)PTR_OCSP_RESPONSE_print_006a8888)(iStack_6ac,ppuVar17,0);
              }
              if (iStack_5e4 == 0) {
                ppuVar24 = (undefined **)
                           setup_verify(*(undefined4 *)puVar15,puStack_618,puStack_614);
                if (ppuVar24 == (undefined **)0x0) {
                  puVar23 = (undefined *)0x1;
                  puVar19 = (undefined *)0x0;
                  iVar2 = 0;
                  goto LAB_00471618;
                }
                if (puStack_628 == (undefined *)0x0) {
                  puVar19 = (undefined *)0x0;
                }
                else {
                  puVar19 = (undefined *)
                            load_certs(*(undefined4 *)PTR_bio_err_006a7f3c,puStack_628,3,0,0,
                                       "validator certificate");
                  if (puVar19 == (undefined *)0x0) {
                    puVar23 = (undefined *)0x1;
                    iVar2 = 0;
                    goto LAB_00471618;
                  }
                }
                iVar2 = (*(code *)PTR_OCSP_response_get1_basic_006a8ef8)(ppuVar17);
                if (iVar2 == 0) {
                  puVar23 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar15,"Error parsing response\n");
                  goto LAB_00471618;
                }
                if (iStack_624 == 0) {
                  if ((iStack_5e8 != 0) &&
                     (iVar4 = (*(code *)PTR_OCSP_check_nonce_006a8efc)(iStack_5e8,iVar2), iVar4 < 1)
                     ) {
                    if (iVar4 != -1) {
                      puVar23 = (undefined *)0x1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar15,"Nonce Verify error\n");
                      goto LAB_00471618;
                    }
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar15,"WARNING: no nonce in response\n");
                  }
                  iVar4 = (*(code *)PTR_OCSP_basic_verify_006a8f00)
                                    (iVar2,puVar19,ppuVar24,uStack_63c);
                  if (iVar4 < 0) {
                    iVar4 = (*(code *)PTR_OCSP_basic_verify_006a8f00)(iVar2,0,ppuVar24,0);
                  }
                  if (iVar4 < 1) {
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar15,"Response Verify Failure\n");
                    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar15);
                  }
                  else {
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar15,"Response verify OK\n");
                  }
                }
                if (((iStack_5e8 == 0) ||
                    (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(uStack_684), iVar4 == 0)) ||
                   (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(uStack_68c), iVar4 == 0)) {
                  puVar23 = (undefined *)0x0;
                  goto LAB_00471618;
                }
                iVar4 = 0;
                pcStack_6b0 = "s\n";
                puStack_6a0 = &DAT_00632848;
                pcStack_69c = "s\n";
                goto LAB_004731a8;
              }
              iStack_674 = iStack_674 - (uint)(0 < iStack_674);
              if (iStack_674 == 0) goto LAB_00472c58;
              (*(code *)PTR_BIO_free_all_006a7f74)();
              iStack_5e4 = 0;
              (*(code *)PTR_OCSP_REQUEST_free_006a8864)(iStack_5e8);
              iStack_5e8 = 0;
              (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(ppuVar17);
              ppuVar17 = (undefined **)0x0;
              goto LAB_00471cc4;
            }
            uVar8 = (*(code *)PTR_OCSP_response_status_str_006a8eec)(iVar2);
            (*(code *)PTR_BIO_printf_006a7f38)(iStack_6ac,"Responder Error: %s (%d)\n",uVar8,iVar2);
          } while (iStack_638 != 0);
          puVar23 = (undefined *)0x0;
          puVar19 = (undefined *)0x0;
          ppuVar24 = (undefined **)0x0;
          iVar2 = 0;
          goto LAB_00471618;
        }
        if (iStack_670 != 2) {
          iStack_670 = 0;
        }
        if (puStack_6b4 == (undefined *)0x0) {
          if (puStack_5f8 == (undefined *)0x0) goto LAB_00471b38;
          uVar8 = (*(code *)PTR_BIO_f_buffer_006a8940)();
          iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
          if (iVar2 == 0) {
            puStack_6b4 = (undefined *)0x0;
          }
          else {
            puStack_6b4 = (undefined *)(*(code *)PTR_BIO_new_accept_006a8ef4)(puVar20);
            if (puStack_6b4 != (undefined *)0x0) {
              (*(code *)PTR_BIO_ctrl_006a7f18)(puStack_6b4,0x76,2,iVar2);
              iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(puStack_6b4,0x65,0,0);
              if (0 < iVar2) {
                ppuVar22 = (undefined **)0x0;
                if (puStack_6bc != (undefined *)0x0) goto LAB_00471b44;
                iStack_610 = 0;
                puStack_6a4 = (undefined *)0x0;
                pcStack_6a8 = (char *)0x0;
                goto LAB_00471c34;
              }
              iVar2 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar15,"Error setting up accept BIO\n");
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar15);
            }
          }
          ppuVar17 = (undefined **)0x0;
          (*(code *)PTR_BIO_free_all_006a7f74)(puStack_6b4);
          (*(code *)PTR_BIO_free_006a7f70)(iVar2);
        }
        else {
          ppuVar17 = (undefined **)(*(code *)PTR_BIO_new_file_006a7fac)(puStack_6b4,&DAT_006347ac);
          if (ppuVar17 == (undefined **)0x0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar15,"Error Opening OCSP request file\n");
          }
          else {
            iStack_5e8 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                   (PTR_OCSP_REQUEST_new_006a886c,PTR_d2i_OCSP_REQUEST_006a8e80,
                                    ppuVar17,0);
            (*(code *)PTR_BIO_free_006a7f70)(ppuVar17);
            if (iStack_5e8 != 0) goto LAB_00471b38;
            ppuVar17 = (undefined **)0x0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar15,"Error reading OCSP request\n");
          }
        }
      }
    }
    puStack_6b8 = (undefined *)0x0;
    pcStack_694 = (char *)0x0;
    ppuVar24 = (undefined **)0x0;
    ppuVar22 = (undefined **)0x0;
    puVar19 = (undefined *)0x0;
    puVar23 = (undefined *)0x1;
    puStack_6b4 = (undefined *)0x0;
    iVar2 = 0;
    puStack_6a4 = (undefined *)0x0;
    puStack_698 = (undefined *)0x0;
    pcStack_6a8 = (char *)0x0;
    puStack_6bc = (undefined *)0x0;
  } while( true );
LAB_004712e4:
  do {
    pcVar14 = (char *)ppuStack_550;
    iVar4 = (**(code **)(puStack_518 + -0x704c))(unaff_s7);
  } while (iVar4 == -1);
  pcVar25 = *(code **)(puStack_518 + -0x7048);
LAB_00471280:
  (*pcVar25)(ppuStack_550);
  puStack_558 = puStack_500;
  if (puStack_500 == (undefined *)0x0) {
    puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
LAB_00471464:
    pcVar14 = "Error querying OCSP responsder\n";
    (**(code **)(puStack_518 + -0x7fa8))(*puVar5);
    puStack_558 = (undefined *)0x0;
  }
LAB_00471048:
  if (iVar2 != 0) goto LAB_00471050;
  goto LAB_00471060;
LAB_004731a8:
  iVar6 = (*(code *)PTR_sk_num_006a7f2c)(uStack_68c);
  if (iVar4 < iVar6) {
    puStack_678 = (undefined *)(*(code *)PTR_sk_value_006a7f24)(uStack_68c,iVar4);
    uVar8 = (*(code *)PTR_sk_value_006a7f24)(uStack_684,iVar4);
    (*(code *)PTR_BIO_printf_006a7f38)(iStack_6ac,&DAT_00632848,uVar8);
    iVar6 = (*(code *)PTR_OCSP_resp_find_status_006a8f04)
                      (iVar2,puStack_678,&iStack_5dc,&iStack_5d8,&uStack_5d4,&iStack_5d0,&iStack_5cc
                      );
    if (iVar6 == 0) {
      (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"ERROR: No Status found.\n");
LAB_00473258:
      iVar4 = iVar4 + 1;
    }
    else {
      iVar6 = (*(code *)PTR_OCSP_check_validity_006a8f08)
                        (iStack_5d0,iStack_5cc,iStack_620,iStack_61c);
      if (iVar6 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(iStack_6ac);
      }
      uVar8 = (*(code *)PTR_OCSP_cert_status_str_006a8f0c)(iStack_5dc);
      (*(code *)PTR_BIO_printf_006a7f38)(iStack_6ac,"%s\n",uVar8);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_6ac,iStack_5d0);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\n");
      if (iStack_5cc != 0) {
        (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_6ac,iStack_5cc);
        (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\n");
      }
      if (iStack_5dc != 1) goto LAB_00473258;
      if (iStack_5d8 != -1) {
        uVar8 = (*(code *)PTR_OCSP_crl_reason_str_006a8f14)();
        (*(code *)PTR_BIO_printf_006a7f38)(iStack_6ac,"\tReason: %s\n",uVar8);
      }
      iVar4 = iVar4 + 1;
      (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_6ac,uStack_5d4);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_6ac,"\n");
    }
    goto LAB_004731a8;
  }
  puVar23 = (undefined *)0x0;
  unaff_s7 = (undefined **)0x637a20;
  goto LAB_00471618;
}

