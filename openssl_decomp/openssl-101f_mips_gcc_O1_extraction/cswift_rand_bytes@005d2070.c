
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 * cswift_rand_bytes(undefined *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 **ppuVar13;
  undefined4 uVar14;
  char *pcVar15;
  char *pcVar16;
  int unaff_s2;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 *unaff_s5;
  code *unaff_s6;
  code *pcVar17;
  undefined4 *unaff_s8;
  undefined4 uStack_7f0;
  int iStack_7ec;
  undefined4 uStack_7e8;
  int *piStack_7e4;
  undefined4 uStack_7e0;
  undefined4 uStack_7dc;
  undefined4 uStack_7d8;
  undefined4 uStack_7d4;
  undefined4 uStack_7d0;
  undefined4 uStack_7cc;
  undefined4 uStack_7c8;
  undefined4 uStack_7c4;
  undefined4 uStack_7c0;
  undefined4 *puStack_7b4;
  int iStack_7b0;
  undefined4 uStack_7ac;
  int iStack_7a8;
  undefined auStack_7a4 [16];
  int iStack_794;
  undefined *puStack_790;
  undefined4 *puStack_78c;
  undefined4 **ppuStack_788;
  undefined4 **ppuStack_784;
  undefined4 **ppuStack_780;
  undefined4 **ppuStack_77c;
  undefined4 *puStack_778;
  undefined *puStack_774;
  char *pcStack_770;
  code *pcStack_76c;
  char *pcStack_764;
  undefined4 **ppuStack_758;
  undefined4 uStack_754;
  undefined *puStack_750;
  int iStack_744;
  undefined4 uStack_73c;
  undefined4 *puStack_738;
  int iStack_734;
  undefined4 *puStack_730;
  undefined4 *puStack_72c;
  undefined4 uStack_728;
  undefined4 uStack_724;
  undefined4 *puStack_720;
  undefined4 uStack_71c;
  undefined4 *puStack_718;
  undefined4 uStack_714;
  undefined4 *puStack_710;
  undefined4 uStack_70c;
  undefined4 uStack_708;
  undefined4 *apuStack_6fc [4];
  int iStack_6ec;
  undefined *puStack_6e8;
  char *pcStack_6e4;
  undefined4 **ppuStack_6e0;
  undefined4 **ppuStack_6dc;
  undefined4 **ppuStack_6d8;
  undefined4 **ppuStack_6d4;
  undefined4 *puStack_6d0;
  undefined4 *puStack_6cc;
  undefined4 *puStack_6c8;
  code *pcStack_6c4;
  undefined4 **ppuStack_6b0;
  undefined4 uStack_6ac;
  undefined *puStack_6a8;
  undefined4 **ppuStack_69c;
  undefined4 *puStack_698;
  int iStack_694;
  undefined4 uStack_68c;
  undefined4 uStack_688;
  undefined4 *puStack_684;
  undefined4 *puStack_680;
  undefined4 *puStack_67c;
  undefined4 uStack_678;
  uint uStack_674;
  int iStack_670;
  uint uStack_66c;
  int iStack_668;
  uint uStack_664;
  int iStack_660;
  uint uStack_65c;
  int iStack_658;
  uint uStack_654;
  int iStack_650;
  undefined4 *apuStack_64c [4];
  int iStack_63c;
  undefined4 **ppuStack_638;
  undefined *puStack_634;
  char *pcStack_630;
  char *pcStack_62c;
  undefined4 **ppuStack_628;
  undefined4 **ppuStack_624;
  undefined4 *puStack_620;
  undefined4 *puStack_61c;
  undefined4 *puStack_618;
  code *pcStack_614;
  undefined4 **ppuStack_600;
  undefined4 *puStack_5fc;
  undefined *puStack_5f8;
  undefined4 **ppuStack_5ec;
  undefined4 uStack_5e4;
  undefined4 uStack_5e0;
  undefined4 *puStack_5dc;
  undefined4 *puStack_5d8;
  undefined4 uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5c4;
  undefined4 uStack_5c0;
  undefined4 *apuStack_5a4 [4];
  undefined4 **ppuStack_594;
  undefined4 uStack_590;
  undefined *puStack_58c;
  undefined4 *puStack_588;
  char *pcStack_584;
  undefined4 *puStack_580;
  undefined4 *puStack_57c;
  int iStack_578;
  undefined4 *puStack_574;
  undefined4 *puStack_570;
  code *pcStack_56c;
  undefined4 **ppuStack_558;
  undefined4 *puStack_554;
  undefined *puStack_550;
  char *pcStack_544;
  undefined4 uStack_53c;
  undefined4 uStack_538;
  undefined4 uStack_534;
  undefined4 *puStack_530;
  undefined4 uStack_52c;
  undefined4 uStack_528;
  undefined4 uStack_524;
  undefined4 uStack_520;
  undefined4 uStack_51c;
  undefined4 uStack_518;
  undefined4 *apuStack_4fc [4];
  undefined4 **ppuStack_4ec;
  undefined1 *puStack_4e8;
  undefined *puStack_4e4;
  undefined1 *puStack_4e0;
  undefined1 *puStack_4dc;
  undefined1 *puStack_4d8;
  undefined1 *puStack_4d4;
  code *pcStack_4d0;
  undefined4 *puStack_4cc;
  undefined4 *puStack_4c8;
  code *pcStack_4c4;
  int iStack_4b0;
  undefined4 uStack_4ac;
  undefined *puStack_4a8;
  undefined4 uStack_4a0;
  int iStack_49c;
  undefined4 *puStack_498;
  undefined *puStack_494;
  int iStack_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  undefined4 *puStack_484;
  code *pcStack_480;
  undefined *puStack_47c;
  undefined4 local_44c;
  undefined4 local_448;
  undefined *local_444;
  undefined auStack_440 [20];
  undefined auStack_42c [1024];
  int local_2c;
  
  puStack_6cc = (undefined4 *)PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_44c);
  if (iVar1 == 0) {
    unaff_s6 = (code *)&_ITM_registerTMCloneTable;
    if (0x3ff < (int)param_2) {
      unaff_s5 = &local_448;
      unaff_s4 = 0x400;
      unaff_s3 = 1;
      do {
        local_448 = 0x400;
        local_444 = param_1;
        unaff_s2 = (*(code *)p_CSwift_SimpleRequest)(local_44c,5,0,0);
        if (unaff_s2 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          puVar4 = auStack_42c;
          (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c");
          goto LAB_005d219c;
        }
        param_2 = param_2 - 0x400;
        param_1 = param_1 + 0x400;
      } while (0x3ff < param_2);
    }
    if (param_2 == 0) {
      puStack_498 = (undefined4 *)0x1;
    }
    else {
      local_448 = 0x400;
      local_444 = auStack_42c;
      unaff_s2 = (*(code *)p_CSwift_SimpleRequest)(local_44c,5,0,0);
      if (unaff_s2 == 0) {
        puStack_498 = (undefined4 *)0x1;
        (*(code *)PTR_memcpy_006aabf4)(param_1,local_444,param_2);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        puVar4 = auStack_440;
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c");
LAB_005d219c:
        (*(code *)PTR___sprintf_chk_006aaa40)(puVar4,1,0x14,&DAT_0066fa48);
        puStack_498 = (undefined4 *)0x0;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",puVar4);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_44c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    puStack_498 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x6c,0x6c,"e_cswift.c");
  }
  if (local_2c == *puStack_6cc) {
    return puStack_498;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_4e4 = PTR___stack_chk_guard_006aabf0;
  puStack_47c = (undefined *)puStack_6cc;
  puStack_4a8 = &_gp;
  iStack_49c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_494 = param_1;
  iStack_490 = unaff_s2;
  uStack_48c = unaff_s3;
  uStack_488 = unaff_s4;
  puStack_484 = unaff_s5;
  pcStack_480 = unaff_s6;
  if (cswift_dso == 0) {
    pcVar15 = CSWIFT_LIBNAME;
    if (CSWIFT_LIBNAME == (char *)0x0) {
      pcVar15 = "swift";
    }
    pcStack_584 = (char *)0x0;
    iStack_578 = 0;
    cswift_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar15);
    if (cswift_dso == 0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_4a8 + -0x589c))();
      }
      pcVar17 = *(code **)(puStack_4a8 + -0x6eb0);
      iStack_578 = 0x6a;
      iStack_4b0 = 0x18d;
      goto LAB_005d23cc;
    }
    unaff_s6 = (code *)(**(code **)(puStack_4a8 + -0x6534))(cswift_dso,"swAcquireAccContext");
    if (((unaff_s6 == (code *)0x0) ||
        (puStack_6cc = (undefined4 *)
                       (**(code **)(puStack_4a8 + -0x6534))(cswift_dso,"swAttachKeyParam"),
        puStack_6cc == (undefined4 *)0x0)) ||
       (unaff_s8 = (undefined4 *)(**(code **)(puStack_4a8 + -0x6534))(cswift_dso,"swSimpleRequest"),
       unaff_s8 == (undefined4 *)0x0)) {
LAB_005d25a8:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_4a8 + -0x589c))();
      }
      pcVar17 = *(code **)(puStack_4a8 + -0x6eb0);
      iStack_578 = 0x6a;
      iStack_4b0 = 0x199;
      goto LAB_005d23cc;
    }
    pcStack_544 = "swReleaseAccContext";
    pcVar17 = (code *)(**(code **)(puStack_4a8 + -0x6534))(cswift_dso);
    if (pcVar17 == (code *)0x0) goto LAB_005d25a8;
    p_CSwift_ReleaseAccContext = pcVar17;
    p_CSwift_SimpleRequest = unaff_s8;
    p_CSwift_AttachKeyParam = puStack_6cc;
    p_CSwift_AcquireAccContext = unaff_s6;
    iVar1 = (*unaff_s6)(&uStack_4a0);
    if (iVar1 != 0) {
      unaff_s6 = (code *)&_ITM_registerTMCloneTable;
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_4a8 + -0x589c))();
      }
      iStack_578 = 0x6c;
      pcStack_584 = "e_cswift.c";
      iStack_4b0 = 0x1a5;
      pcStack_544 = &DAT_00000068;
      (**(code **)(puStack_4a8 + -0x6eb0))(CSWIFT_lib_error_code);
      goto LAB_005d23ec;
    }
    (*p_CSwift_ReleaseAccContext)(uStack_4a0);
    puVar2 = (undefined4 *)0x1;
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    pcVar17 = *(code **)(puStack_4a8 + -0x6eb0);
    iStack_578 = 100;
    iStack_4b0 = 0x186;
LAB_005d23cc:
    pcStack_584 = "e_cswift.c";
    pcStack_544 = &DAT_00000068;
    (*pcVar17)(CSWIFT_lib_error_code);
LAB_005d23ec:
    if (cswift_dso != 0) {
      (**(code **)(puStack_4a8 + -0x654c))();
      cswift_dso = 0;
    }
    puVar2 = (undefined4 *)0x0;
    p_CSwift_AcquireAccContext = (code *)0x0;
    p_CSwift_AttachKeyParam = (undefined4 *)0x0;
    p_CSwift_SimpleRequest = (undefined4 *)0x0;
    p_CSwift_ReleaseAccContext = (code *)0x0;
  }
  puStack_57c = (undefined4 *)&_ITM_registerTMCloneTable;
  puStack_580 = (undefined4 *)&_ITM_registerTMCloneTable;
  if (iStack_49c == *(int *)puStack_4e4) {
    return puVar2;
  }
  pcStack_4c4 = cswift_mod_exp_dh;
  (**(code **)(puStack_4a8 + -0x5328))();
  iVar1 = iStack_4b0;
  puStack_58c = PTR___stack_chk_guard_006aabf0;
  puStack_4dc = &_ITM_registerTMCloneTable;
  puStack_4e0 = &_ITM_registerTMCloneTable;
  puStack_4e8 = &_ITM_registerTMCloneTable;
  puStack_550 = &_gp;
  puStack_4d4 = &_ITM_registerTMCloneTable;
  puStack_4d8 = &_ITM_registerTMCloneTable;
  ppuStack_4ec = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  pcStack_4d0 = unaff_s6;
  puStack_4cc = puStack_6cc;
  puStack_4c8 = unaff_s8;
  iVar3 = (*p_CSwift_AcquireAccContext)(&uStack_53c);
  if (iVar3 == 0) {
    (**(code **)(puStack_550 + -0x689c))(uStack_4ac);
    puStack_580 = (undefined4 *)(**(code **)(puStack_550 + -0x6898))(uStack_4ac);
    puStack_6cc = (undefined4 *)(**(code **)(puStack_550 + -0x6898))(uStack_4ac);
    unaff_s8 = (undefined4 *)(**(code **)(puStack_550 + -0x6898))(uStack_4ac);
    puStack_57c = (undefined4 *)(**(code **)(puStack_550 + -0x6898))(uStack_4ac);
    if (puStack_57c == (undefined4 *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
      }
      pcVar17 = *(code **)(puStack_550 + -0x6eb0);
      ppuStack_780 = (undefined4 **)0x66;
      ppuStack_558 = (undefined4 **)0x20a;
LAB_005d29fc:
      pcStack_62c = "e_cswift.c";
      pcStack_630 = &DAT_00000069;
      puStack_588 = (undefined4 *)0x0;
      (*pcVar17)(CSWIFT_lib_error_code);
    }
    else {
      pcVar17 = *(code **)(puStack_550 + -0x6860);
      if ((int)puStack_580[2] < *(int *)(iVar1 + 4)) {
        iVar3 = (*pcVar17)(puStack_580);
        if (iVar3 != 0) {
          if ((int)puStack_6cc[2] < (int)*(undefined4 **)((int)pcStack_584 + 4)) {
            pcVar17 = *(code **)(puStack_550 + -0x6860);
            goto LAB_005d2a4c;
          }
          goto LAB_005d27e0;
        }
LAB_005d299c:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_550 + -0x6eb0);
        ppuStack_780 = (undefined4 **)0x67;
        ppuStack_558 = (undefined4 **)0x210;
        goto LAB_005d29fc;
      }
      if ((int)puStack_6cc[2] < (int)*(undefined4 **)((int)pcStack_584 + 4)) {
LAB_005d2a4c:
        iVar3 = (*pcVar17)(puStack_6cc);
        if (iVar3 == 0) goto LAB_005d299c;
      }
LAB_005d27e0:
      if ((((int)unaff_s8[2] < *(int *)(iStack_578 + 4)) &&
          (iVar3 = (**(code **)(puStack_550 + -0x6860))(unaff_s8), iVar3 == 0)) ||
         (((int)puStack_57c[2] < *(int *)(iVar1 + 4) &&
          (iVar3 = (**(code **)(puStack_550 + -0x6860))(puStack_57c), iVar3 == 0))))
      goto LAB_005d299c;
      uStack_528 = 2;
      uStack_524 = (**(code **)(puStack_550 + -0x7be0))(iVar1,*puStack_580);
      uStack_520 = *puStack_580;
      uStack_51c = (**(code **)(puStack_550 + -0x7be0))(pcStack_584,*puStack_6cc);
      uStack_518 = *puStack_6cc;
      pcStack_584 = (char *)(*(code *)p_CSwift_AttachKeyParam)(uStack_53c,&uStack_528);
      if ((undefined4 **)pcStack_584 == (undefined4 **)0xffffd8ea) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_550 + -0x6eb0);
        ppuStack_780 = (undefined4 **)&DAT_00000065;
        ppuStack_558 = (undefined4 **)0x221;
        goto LAB_005d29fc;
      }
      if ((undefined4 **)pcStack_584 == (undefined4 **)0x0) {
        uStack_538 = (**(code **)(puStack_550 + -0x7be0))(iStack_578,*unaff_s8);
        uStack_534 = *unaff_s8;
        iVar3 = (**(code **)(puStack_550 + -0x7bec))(iVar1);
        iVar1 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar1 = iVar3 + 0xe;
        }
        puStack_530 = (undefined4 *)(iVar1 >> 3);
        (**(code **)(puStack_550 + -0x53e0))(*puStack_57c,0,puStack_530);
        uStack_52c = *puStack_57c;
        pcStack_62c = (char *)0x1;
        ppuStack_558 = &puStack_530;
        puStack_554 = (undefined4 *)0x1;
        ppuVar13 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_53c,2,&uStack_538);
        if (ppuVar13 != (undefined4 **)0x0) {
          pcStack_584 = &_ITM_registerTMCloneTable;
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
          }
          ppuStack_558 = (undefined4 **)0x237;
          (**(code **)(puStack_550 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_550 + -0x54a0);
          ppuStack_558 = ppuVar13;
          goto LAB_005d2ac0;
        }
        puStack_588 = (undefined4 *)0x1;
        pcStack_630 = (char *)puStack_530;
        ppuStack_780 = (undefined4 **)pcStack_544;
        (**(code **)(puStack_550 + -0x74f0))(*puStack_57c);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
        }
        ppuStack_558 = (undefined4 **)0x226;
        (**(code **)(puStack_550 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
        pcVar17 = *(code **)(puStack_550 + -0x54a0);
        ppuStack_558 = (undefined4 **)pcStack_584;
LAB_005d2ac0:
        pcStack_62c = &DAT_0066fa48;
        ppuStack_780 = apuStack_4fc;
        (*pcVar17)(ppuStack_780,1,0xd);
        pcStack_630 = "CryptoSwift error number is ";
        puStack_588 = (undefined4 *)0x0;
        (**(code **)(puStack_550 + -0x6c7c))(2);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_53c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (**(code **)(puStack_550 + -0x589c))();
    }
    ppuStack_780 = (undefined4 **)&DAT_0000006c;
    pcStack_62c = "e_cswift.c";
    ppuStack_558 = (undefined4 **)0x1fe;
    pcStack_630 = &DAT_00000069;
    puStack_588 = (undefined4 *)0x0;
    (**(code **)(puStack_550 + -0x6eb0))(CSWIFT_lib_error_code);
  }
  (**(code **)(puStack_550 + -0x688c))(uStack_4ac);
  if (ppuStack_4ec == *(undefined4 ***)puStack_58c) {
    return puStack_588;
  }
  pcStack_56c = cswift_mod_exp_mont;
  ppuStack_77c = ppuStack_4ec;
  (**(code **)(puStack_550 + -0x5328))();
  puStack_778 = puStack_554;
  ppuStack_638 = ppuStack_558;
  puStack_634 = PTR___stack_chk_guard_006aabf0;
  uStack_590 = uStack_4ac;
  puStack_5f8 = &_gp;
  ppuStack_594 = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  puStack_574 = puStack_6cc;
  puStack_570 = unaff_s8;
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
  if ((((iVar1 < 0x801) &&
       (iVar1 = (**(code **)(puStack_5f8 + -0x7bec))(pcStack_630), iVar1 < 0x801)) &&
      (iVar1 = (**(code **)(puStack_5f8 + -0x7bec))(pcStack_62c), iVar1 < 0x801)) ||
     (iVar1 = (**(code **)(puStack_5f8 + -0x7308))(), iVar1 == 0)) {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_5e4);
    if (iVar1 == 0) {
      (**(code **)(puStack_5f8 + -0x689c))(ppuStack_638);
      puStack_778 = (undefined4 *)(**(code **)(puStack_5f8 + -0x6898))(ppuStack_638);
      puStack_6cc = (undefined4 *)(**(code **)(puStack_5f8 + -0x6898))(ppuStack_638);
      ppuStack_5ec = (undefined4 **)(**(code **)(puStack_5f8 + -0x6898))(ppuStack_638);
      unaff_s8 = (undefined4 *)(**(code **)(puStack_5f8 + -0x6898))(ppuStack_638);
      if (unaff_s8 == (undefined4 *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_5f8 + -0x6eb0);
        ppuStack_784 = (undefined4 **)0x66;
        ppuStack_600 = (undefined4 **)0x20a;
LAB_005d2f9c:
        pcVar15 = "e_cswift.c";
        pcStack_6e4 = &DAT_00000069;
        puVar2 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if ((((((int)puStack_778[2] < (int)*(undefined4 **)((int)pcStack_62c + 4)) &&
              (iVar1 = (**(code **)(puStack_5f8 + -0x6860))(puStack_778), iVar1 == 0)) ||
             (((int)puStack_6cc[2] < (int)ppuStack_780[1] &&
              (iVar1 = (**(code **)(puStack_5f8 + -0x6860))(puStack_6cc), iVar1 == 0)))) ||
            (((int)ppuStack_5ec[2] < *(int *)((int)pcStack_630 + 4) &&
             (iVar1 = (**(code **)(puStack_5f8 + -0x6860))(ppuStack_5ec), iVar1 == 0)))) ||
           (((int)unaff_s8[2] < (int)*(undefined4 **)((int)pcStack_62c + 4) &&
            (iVar1 = (**(code **)(puStack_5f8 + -0x6860))(unaff_s8), iVar1 == 0)))) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_5f8 + -0x6eb0);
          ppuStack_784 = (undefined4 **)0x67;
          ppuStack_600 = (undefined4 **)0x210;
          goto LAB_005d2f9c;
        }
        uStack_5d0 = 2;
        uStack_5cc = (**(code **)(puStack_5f8 + -0x7be0))(pcStack_62c,*puStack_778);
        uStack_5c8 = *puStack_778;
        uStack_5c4 = (**(code **)(puStack_5f8 + -0x7be0))(ppuStack_780,*puStack_6cc);
        uStack_5c0 = *puStack_6cc;
        ppuVar13 = (undefined4 **)(*(code *)p_CSwift_AttachKeyParam)(uStack_5e4,&uStack_5d0);
        ppuStack_780 = ppuStack_5ec;
        if (ppuVar13 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_5f8 + -0x6eb0);
          ppuStack_784 = (undefined4 **)&DAT_00000065;
          ppuStack_600 = (undefined4 **)0x221;
          ppuStack_780 = ppuVar13;
          goto LAB_005d2f9c;
        }
        if (ppuVar13 == (undefined4 **)0x0) {
          uStack_5e0 = (**(code **)(puStack_5f8 + -0x7be0))(pcStack_630,*ppuStack_5ec);
          puStack_5dc = *ppuStack_780;
          iVar3 = (**(code **)(puStack_5f8 + -0x7bec))(pcStack_62c);
          iVar1 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            iVar1 = iVar3 + 0xe;
          }
          puStack_5d8 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_5f8 + -0x53e0))(*unaff_s8,0,puStack_5d8);
          uStack_5d4 = *unaff_s8;
          pcVar15 = (char *)0x1;
          ppuStack_600 = &puStack_5d8;
          puStack_5fc = (undefined4 *)0x1;
          ppuVar13 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_5e4,2,&uStack_5e0);
          if (ppuVar13 != (undefined4 **)0x0) {
            pcStack_62c = &_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
            }
            ppuStack_600 = (undefined4 **)0x237;
            (**(code **)(puStack_5f8 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_5f8 + -0x54a0);
            ppuStack_600 = ppuVar13;
            goto LAB_005d3034;
          }
          puVar2 = (undefined4 *)0x1;
          pcStack_6e4 = (char *)puStack_5d8;
          ppuStack_784 = ppuStack_77c;
          (**(code **)(puStack_5f8 + -0x74f0))(*unaff_s8);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
          }
          ppuStack_600 = (undefined4 **)0x226;
          (**(code **)(puStack_5f8 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_5f8 + -0x54a0);
          ppuStack_780 = ppuVar13;
          ppuStack_600 = ppuVar13;
LAB_005d3034:
          pcVar15 = &DAT_0066fa48;
          ppuStack_784 = apuStack_5a4;
          (*pcVar17)(ppuStack_784,1,0xd);
          pcStack_6e4 = "CryptoSwift error number is ";
          puVar2 = (undefined4 *)0x0;
          (**(code **)(puStack_5f8 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_5e4);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_5f8 + -0x589c))();
      }
      ppuStack_784 = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      ppuStack_600 = (undefined4 **)0x1fe;
      pcStack_6e4 = &DAT_00000069;
      puVar2 = (undefined4 *)0x0;
      (**(code **)(puStack_5f8 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_5f8 + -0x688c))(ppuStack_638);
    pcStack_630 = (char *)puVar2;
  }
  else {
    puStack_5fc = puStack_778;
    ppuStack_600 = ppuStack_638;
    pcStack_6e4 = pcStack_630;
    ppuStack_784 = ppuStack_780;
    pcVar15 = pcStack_62c;
    puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x18))(ppuStack_77c);
  }
  if (ppuStack_594 == *(undefined4 ***)puStack_634) {
    return puVar2;
  }
  pcStack_614 = cswift_rsa_mod_exp;
  ppuVar13 = ppuStack_594;
  (**(code **)(puStack_5f8 + -0x5328))();
  puStack_790 = PTR___stack_chk_guard_006aabf0;
  puStack_6a8 = &_gp;
  iStack_63c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar5 = (undefined4 **)pcStack_62c;
  ppuStack_788 = ppuVar13;
  ppuStack_628 = ppuStack_780;
  ppuStack_624 = ppuStack_77c;
  puStack_620 = puStack_778;
  puStack_61c = puStack_6cc;
  puStack_618 = unaff_s8;
  if ((((ppuStack_784[7] == (undefined4 *)0x0) ||
       (ppuVar5 = ppuStack_784, ppuStack_784[8] == (undefined4 *)0x0)) ||
      (ppuStack_784[9] == (undefined4 *)0x0)) ||
     ((ppuStack_784[10] == (undefined4 *)0x0 || (ppuStack_784[0xb] == (undefined4 *)0x0)))) {
    ppuStack_784 = ppuVar5;
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar16 = "e_cswift.c";
    ppuStack_6b0 = (undefined4 **)0x2ed;
    pcStack_770 = &DAT_0000006b;
    (**(code **)(puStack_6a8 + -0x6eb0))(CSWIFT_lib_error_code);
    puVar2 = (undefined4 *)0x0;
    pcStack_6e4 = &_ITM_registerTMCloneTable;
  }
  else {
    pcVar16 = pcVar15;
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    if ((((iVar1 < 0x401) &&
         (iVar1 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_784[8]), iVar1 < 0x401)) &&
        ((iVar1 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_784[9]), iVar1 < 0x401 &&
         ((iVar1 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_784[10]), iVar1 < 0x401 &&
          (iVar1 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_784[0xb]), iVar1 < 0x401)))))) ||
       (iVar1 = (**(code **)(puStack_6a8 + -0x7308))(), pcVar16 = pcVar15, iVar1 == 0)) {
      ppuStack_77c = (undefined4 **)ppuStack_784[7];
      puStack_778 = ppuStack_784[8];
      unaff_s8 = ppuStack_784[9];
      ppuStack_69c = (undefined4 **)ppuStack_784[10];
      iStack_670 = 0;
      iStack_668 = 0;
      iStack_660 = 0;
      iStack_658 = 0;
      iStack_650 = 0;
      puStack_698 = ppuStack_784[0xb];
      iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_68c);
      if (iVar1 == 0) {
        ppuStack_780 = (undefined4 **)(**(code **)(puStack_6a8 + -0x7c2c))();
        ppuStack_784 = (undefined4 **)(**(code **)(puStack_6a8 + -0x7c2c))();
        if ((ppuStack_784 == (undefined4 **)0x0) || (ppuStack_780 == (undefined4 **)0x0)) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
          }
          ppuVar13 = (undefined4 **)0x66;
          pcVar16 = "e_cswift.c";
          ppuStack_6b0 = (undefined4 **)0x280;
          pcStack_770 = &DAT_0000006a;
          ppuStack_788 = (undefined4 **)0x1;
          (**(code **)(puStack_6a8 + -0x6eb0))(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
        else {
          uStack_678 = 1;
          iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_77c);
          iVar1 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            iVar1 = iVar3 + 0xe;
          }
          uStack_674 = iVar1 >> 3;
          if ((uStack_674 & 0x1f) == 0) {
            iStack_670 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_674,"e_cswift.c",0x252);
            if (iStack_670 == 0) goto LAB_005d398c;
            (**(code **)(puStack_6a8 + -0x7be0))(ppuStack_77c,iStack_670);
LAB_005d33d8:
            puStack_6cc = (undefined4 *)0x670000;
            iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(puStack_778);
            iVar1 = iVar3 + 7;
            if (iVar3 + 7 < 0) {
              iVar1 = iVar3 + 0xe;
            }
            uStack_66c = iVar1 >> 3;
            if ((uStack_66c & 0x1f) == 0) {
              iStack_668 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_66c,"e_cswift.c",0x252);
              if (iStack_668 != 0) {
                (**(code **)(puStack_6a8 + -0x7be0))(puStack_778,iStack_668);
                goto LAB_005d3480;
              }
            }
            else {
              iStack_694 = 0;
              do {
                uStack_66c = uStack_66c + 1;
                iStack_694 = iStack_694 + 1;
              } while ((uStack_66c & 0x1f) != 0);
              iStack_668 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_66c,"e_cswift.c",0x252);
              if (iStack_668 != 0) {
                (**(code **)(puStack_6a8 + -0x7be0))(puStack_778,iStack_668 + iStack_694);
                (**(code **)(puStack_6a8 + -0x53e0))(iStack_668,0,iStack_694);
LAB_005d3480:
                iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(unaff_s8);
                iVar1 = iVar3 + 7;
                if (iVar3 + 7 < 0) {
                  iVar1 = iVar3 + 0xe;
                }
                uStack_664 = iVar1 >> 3;
                if ((uStack_664 & 0x1f) == 0) {
                  iStack_660 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_664,"e_cswift.c",0x252);
                  if (iStack_660 == 0) goto LAB_005d3a20;
                  (**(code **)(puStack_6a8 + -0x7be0))(unaff_s8,iStack_660);
                }
                else {
                  iStack_694 = 0;
                  do {
                    uStack_664 = uStack_664 + 1;
                    iStack_694 = iStack_694 + 1;
                  } while ((uStack_664 & 0x1f) != 0);
                  iStack_660 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_664,"e_cswift.c",0x252);
                  if (iStack_660 == 0) {
LAB_005d3a20:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_6a8 + -0x6eb0);
                    ppuStack_6b0 = (undefined4 **)0x297;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_6a8 + -0x7be0))(unaff_s8,iStack_660 + iStack_694);
                  (**(code **)(puStack_6a8 + -0x53e0))(iStack_660,0,iStack_694);
                }
                iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_69c);
                iVar1 = iVar3 + 7;
                if (iVar3 + 7 < 0) {
                  iVar1 = iVar3 + 0xe;
                }
                uStack_65c = iVar1 >> 3;
                if ((uStack_65c & 0x1f) == 0) {
                  iStack_658 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_65c,"e_cswift.c",0x252);
                  if (iStack_658 == 0) goto LAB_005d3acc;
                  (**(code **)(puStack_6a8 + -0x7be0))(ppuStack_69c,iStack_658);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_65c = uStack_65c + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_65c & 0x1f) != 0);
                  iStack_658 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_65c,"e_cswift.c",0x252);
                  if (iStack_658 == 0) {
LAB_005d3acc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_6a8 + -0x6eb0);
                    ppuStack_6b0 = (undefined4 **)0x29c;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_6a8 + -0x7be0))(ppuStack_69c,iStack_658 + (int)unaff_s8);
                  (**(code **)(puStack_6a8 + -0x53e0))(iStack_658,0,unaff_s8);
                }
                iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(puStack_698);
                iVar1 = iVar3 + 7;
                if (iVar3 + 7 < 0) {
                  iVar1 = iVar3 + 0xe;
                }
                uStack_654 = iVar1 >> 3;
                if ((uStack_654 & 0x1f) == 0) {
                  iStack_650 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_654,"e_cswift.c",0x252);
                  if (iStack_650 == 0) goto LAB_005d3b74;
                  (**(code **)(puStack_6a8 + -0x7be0))(puStack_698,iStack_650);
LAB_005d3660:
                  if (((int)ppuStack_780[2] < *(int *)((int)pcStack_6e4 + 4)) &&
                     (iVar1 = (**(code **)(puStack_6a8 + -0x6860))(ppuStack_780), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  if (((int)ppuStack_784[2] < puStack_778[1] + (int)ppuStack_77c[1]) &&
                     (iVar1 = (**(code **)(puStack_6a8 + -0x6860))(ppuStack_784), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  ppuVar5 = (undefined4 **)
                            (*(code *)p_CSwift_AttachKeyParam)(uStack_68c,&uStack_678);
                  if (ppuVar5 != (undefined4 **)0xffffd8ea) {
                    if (ppuVar5 == (undefined4 **)0x0) {
                      uStack_688 = (**(code **)(puStack_6a8 + -0x7be0))(pcStack_6e4,*ppuStack_780);
                      puStack_684 = *ppuStack_780;
                      iVar3 = (**(code **)(puStack_6a8 + -0x7bec))(ppuStack_77c);
                      iVar1 = iVar3 + 7;
                      if (iVar3 + 7 < 0) {
                        iVar1 = iVar3 + 0xe;
                      }
                      puStack_680 = (undefined4 *)((iVar1 >> 3) << 1);
                      (**(code **)(puStack_6a8 + -0x53e0))(*ppuStack_784,0,puStack_680);
                      puStack_67c = *ppuStack_784;
                      pcVar16 = (char *)0x1;
                      ppuStack_6b0 = &puStack_680;
                      uStack_6ac = 1;
                      ppuVar5 = (undefined4 **)
                                (*(code *)p_CSwift_SimpleRequest)(uStack_68c,1,&uStack_688);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_788 = (undefined4 **)0x1;
                        puVar2 = (undefined4 *)0x1;
                        pcStack_770 = (char *)puStack_680;
                        (**(code **)(puStack_6a8 + -0x74f0))(*ppuStack_784);
                        goto LAB_005d3868;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2c8);
                      pcVar17 = *(code **)(puStack_6a8 + -0x54a0);
                      ppuStack_6b0 = ppuVar5;
                    }
                    else {
                      ppuStack_69c = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2b7);
                      pcVar17 = *(code **)(puStack_6a8 + -0x54a0);
                      ppuStack_6b0 = ppuStack_69c;
                    }
                    pcVar16 = &DAT_0066fa48;
                    ppuVar13 = apuStack_64c;
                    (*pcVar17)(ppuVar13,1,0xd);
                    pcStack_770 = "CryptoSwift error number is ";
                    ppuStack_788 = (undefined4 **)0x1;
                    puVar2 = (undefined4 *)0x0;
                    (**(code **)(puStack_6a8 + -0x6c7c))(2);
                    goto LAB_005d3868;
                  }
                  ppuVar13 = (undefined4 **)0x2b2;
                  pcStack_770 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_654 = uStack_654 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_654 & 0x1f) != 0);
                  iStack_650 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_654,"e_cswift.c",0x252);
                  if (iStack_650 != 0) {
                    (**(code **)(puStack_6a8 + -0x7be0))(puStack_698,iStack_650 + (int)unaff_s8);
                    (**(code **)(puStack_6a8 + -0x53e0))(iStack_650,0,unaff_s8);
                    goto LAB_005d3660;
                  }
LAB_005d3b74:
                  ppuVar13 = (undefined4 **)0x2a1;
LAB_005d3b78:
                  pcStack_770 = (char *)0x67;
                }
                ppuStack_788 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar2 = (undefined4 *)0x0;
                goto LAB_005d3868;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
            }
            pcVar17 = *(code **)(puStack_6a8 + -0x6eb0);
            ppuStack_6b0 = (undefined4 **)0x292;
          }
          else {
            iStack_694 = 0;
            do {
              uStack_674 = uStack_674 + 1;
              iStack_694 = iStack_694 + 1;
            } while ((uStack_674 & 0x1f) != 0);
            iStack_670 = (**(code **)(puStack_6a8 + -0x7dd8))(uStack_674,"e_cswift.c",0x252);
            if (iStack_670 != 0) {
              (**(code **)(puStack_6a8 + -0x7be0))(ppuStack_77c,iStack_670 + iStack_694);
              (**(code **)(puStack_6a8 + -0x53e0))(iStack_670,0,iStack_694);
              goto LAB_005d33d8;
            }
LAB_005d398c:
            pcVar17 = *(code **)(puStack_6a8 + -0x6eb0);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
              pcVar17 = *(code **)(puStack_6a8 + -0x6eb0);
            }
            ppuStack_6b0 = (undefined4 **)0x28d;
          }
LAB_005d39c8:
          pcVar16 = "e_cswift.c";
          puStack_6cc = (undefined4 *)0x670000;
          ppuVar13 = (undefined4 **)0x67;
          pcStack_770 = &DAT_0000006a;
          ppuStack_788 = (undefined4 **)0x1;
          (*pcVar17)(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_6a8 + -0x589c))();
        }
        ppuVar13 = (undefined4 **)&DAT_0000006c;
        pcVar16 = "e_cswift.c";
        ppuStack_6b0 = (undefined4 **)0x276;
        pcStack_770 = &DAT_0000006a;
        ppuStack_788 = (undefined4 **)0x0;
        (**(code **)(puStack_6a8 + -0x6eb0))(CSWIFT_lib_error_code);
        puVar2 = (undefined4 *)0x0;
        ppuStack_780 = (undefined4 **)0x0;
        ppuStack_784 = (undefined4 **)0x0;
      }
LAB_005d3868:
      ppuVar5 = ppuVar13;
      if (iStack_670 != 0) {
        (**(code **)(puStack_6a8 + -0x7f58))();
        ppuVar5 = ppuVar13;
      }
      if (iStack_668 != 0) {
        (**(code **)(puStack_6a8 + -0x7f58))();
      }
      if (iStack_660 != 0) {
        (**(code **)(puStack_6a8 + -0x7f58))();
      }
      if (iStack_658 != 0) {
        (**(code **)(puStack_6a8 + -0x7f58))();
      }
      if (iStack_650 != 0) {
        (**(code **)(puStack_6a8 + -0x7f58))();
      }
      if (ppuStack_784 != (undefined4 **)0x0) {
        (**(code **)(puStack_6a8 + -0x7dc4))(ppuStack_784);
      }
      if (ppuStack_780 != (undefined4 **)0x0) {
        (**(code **)(puStack_6a8 + -0x7dc4))(ppuStack_780);
      }
      pcStack_6e4 = (char *)puVar2;
      if (ppuStack_788 != (undefined4 **)0x0) {
        (*p_CSwift_ReleaseAccContext)(uStack_68c);
      }
    }
    else {
      pcStack_770 = pcStack_6e4;
      puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x14))(ppuVar13);
      ppuStack_780 = (undefined4 **)pcVar15;
    }
  }
  if (iStack_63c == *(int *)puStack_790) {
    return puVar2;
  }
  pcStack_6c4 = cswift_dsa_sign;
  iStack_744 = iStack_63c;
  (**(code **)(puStack_6a8 + -0x5328))();
  puStack_774 = PTR___stack_chk_guard_006aabf0;
  puStack_750 = &_gp;
  puStack_6e8 = puStack_790;
  iStack_6ec = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_764 = pcStack_770;
  ppuVar13 = ppuVar5;
  ppuStack_6e0 = ppuStack_788;
  ppuStack_6dc = ppuStack_784;
  ppuStack_6d8 = ppuStack_780;
  ppuStack_6d4 = ppuStack_77c;
  puStack_6d0 = puStack_778;
  puStack_6c8 = unaff_s8;
  puVar4 = (undefined *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  if (puVar4 == (undefined *)0x0) {
    puStack_78c = (undefined4 *)0x0;
  }
  else {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_73c);
    if (iVar1 == 0) {
      (**(code **)(puStack_750 + -0x689c))(puVar4);
      ppuStack_784 = (undefined4 **)(**(code **)(puStack_750 + -0x6898))(puVar4);
      ppuStack_780 = (undefined4 **)(**(code **)(puStack_750 + -0x6898))(puVar4);
      ppuStack_77c = (undefined4 **)(**(code **)(puStack_750 + -0x6898))(puVar4);
      puStack_778 = (undefined4 *)(**(code **)(puStack_750 + -0x6898))(puVar4);
      ppuStack_788 = (undefined4 **)(**(code **)(puStack_750 + -0x6898))(puVar4);
      if (ppuStack_788 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_750 + -0x6eb0);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_758 = (undefined4 **)0x348;
LAB_005d40a4:
        pcVar16 = "e_cswift.c";
        pcStack_764 = &DAT_00000065;
        puStack_78c = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)ppuStack_784[2] < (int)ppuVar5[3][1]) &&
           (iVar1 = (**(code **)(puStack_750 + -0x6860))(ppuStack_784), iVar1 == 0)) {
LAB_005d40cc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_750 + -0x6eb0);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_758 = (undefined4 **)0x351;
          goto LAB_005d40a4;
        }
        pcVar17 = *(code **)(puStack_750 + -0x6860);
        if ((int)ppuStack_780[2] < (int)ppuVar5[4][1]) {
          iVar1 = (*pcVar17)(ppuStack_780);
          if (iVar1 != 0) {
            pcVar17 = *(code **)(puStack_750 + -0x6860);
            if ((int)ppuStack_77c[2] < (int)ppuVar5[5][1]) goto LAB_005d411c;
            goto LAB_005d3da4;
          }
          goto LAB_005d40cc;
        }
        if ((int)ppuStack_77c[2] < (int)ppuVar5[5][1]) {
LAB_005d411c:
          iVar1 = (*pcVar17)(ppuStack_77c);
          if (iVar1 == 0) goto LAB_005d40cc;
          pcVar17 = *(code **)(puStack_750 + -0x6860);
          if ((int)puStack_778[2] < (int)ppuVar5[7][1]) goto LAB_005d4144;
LAB_005d3dbc:
          puVar2 = ppuVar5[3];
          pcVar17 = *(code **)(puStack_750 + -0x6860);
          if ((int)ppuStack_788[2] < (int)puVar2[1]) {
LAB_005d4170:
            iVar1 = (*pcVar17)(ppuStack_788);
            if (iVar1 == 0) goto LAB_005d40cc;
            puVar2 = ppuVar5[3];
          }
        }
        else {
LAB_005d3da4:
          pcVar17 = *(code **)(puStack_750 + -0x6860);
          if ((int)ppuVar5[7][1] <= (int)puStack_778[2]) goto LAB_005d3dbc;
LAB_005d4144:
          iVar1 = (*pcVar17)(puStack_778);
          if (iVar1 == 0) goto LAB_005d40cc;
          puVar2 = ppuVar5[3];
          if ((int)ppuStack_788[2] < (int)puVar2[1]) {
            pcVar17 = *(code **)(puStack_750 + -0x6860);
            goto LAB_005d4170;
          }
        }
        uStack_728 = 3;
        uStack_724 = (**(code **)(puStack_750 + -0x7be0))(puVar2,*ppuStack_784);
        puStack_720 = *ppuStack_784;
        uStack_71c = (**(code **)(puStack_750 + -0x7be0))(ppuVar5[4],*ppuStack_780);
        puStack_718 = *ppuStack_780;
        uStack_714 = (**(code **)(puStack_750 + -0x7be0))(ppuVar5[5],*ppuStack_77c);
        puStack_710 = *ppuStack_77c;
        uStack_70c = (**(code **)(puStack_750 + -0x7be0))(ppuVar5[7],*puStack_778);
        uStack_708 = *puStack_778;
        ppuStack_784 = (undefined4 **)(*(code *)p_CSwift_AttachKeyParam)(uStack_73c,&uStack_728);
        if (ppuStack_784 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_750 + -0x6eb0);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_758 = (undefined4 **)0x368;
          goto LAB_005d40a4;
        }
        if (ppuStack_784 == (undefined4 **)0x0) {
          iStack_734 = iStack_744;
          puStack_738 = (undefined4 *)pcStack_770;
          iVar3 = (**(code **)(puStack_750 + -0x7bec))(ppuVar5[3]);
          iVar1 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            iVar1 = iVar3 + 0xe;
          }
          puStack_730 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_750 + -0x53e0))(*ppuStack_788,0,puStack_730);
          puStack_72c = *ppuStack_788;
          pcVar16 = (char *)0x1;
          ppuVar13 = &puStack_738;
          pcStack_764 = (char *)0x3;
          ppuStack_758 = &puStack_730;
          uStack_754 = 1;
          ppuVar5 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_73c);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_788 = (undefined4 **)&_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
            }
            ppuStack_758 = (undefined4 **)0x37f;
            (**(code **)(puStack_750 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_750 + -0x54a0);
            ppuStack_758 = ppuVar5;
            goto LAB_005d3fd8;
          }
          puStack_78c = (undefined4 *)(**(code **)(puStack_750 + -0x6660))();
          if (puStack_78c != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_750 + -0x74f0))(*ppuStack_788,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_764 = &DAT_00000014;
            puVar2 = *ppuStack_788;
            *puStack_78c = uVar6;
            uVar6 = (**(code **)(puStack_750 + -0x74f0))(puVar2 + 5);
            puStack_78c[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
          }
          ppuStack_758 = (undefined4 **)0x36d;
          (**(code **)(puStack_750 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_750 + -0x54a0);
          ppuStack_758 = ppuStack_784;
LAB_005d3fd8:
          pcVar16 = &DAT_0066fa48;
          ppuVar13 = apuStack_6fc;
          (*pcVar17)(ppuVar13,1,0xd);
          pcStack_764 = "CryptoSwift error number is ";
          puStack_78c = (undefined4 *)0x0;
          (**(code **)(puStack_750 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_73c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_750 + -0x589c))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar16 = "e_cswift.c";
      ppuStack_758 = (undefined4 **)0x33b;
      pcStack_764 = &DAT_00000065;
      puStack_78c = (undefined4 *)0x0;
      (**(code **)(puStack_750 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_750 + -0x688c))(puVar4);
    (**(code **)(puStack_750 + -0x74a0))(puVar4);
    puStack_790 = puVar4;
  }
  if (iStack_6ec == *(int *)puStack_774) {
    return puStack_78c;
  }
  pcStack_76c = cswift_dsa_verify;
  iVar1 = iStack_6ec;
  (**(code **)(puStack_750 + -0x5328))();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  iStack_794 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar3 == 0) {
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005d45fc;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_7f0);
  if (iVar7 == 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar3);
    puVar2 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar8 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar9 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar10 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    piVar11 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    if (piVar11 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar14 = 0x66;
      uVar6 = 0x3b7;
LAB_005d4718:
      puVar2 = (undefined4 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,uVar14,"e_cswift.c",uVar6);
    }
    else {
      if (((int)puVar2[2] < (int)(*(undefined4 **)((int)pcVar16 + 0xc))[1]) &&
         (iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar2), iVar7 == 0)) {
LAB_005d4744:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x67;
        uVar6 = 0x3c0;
        goto LAB_005d4718;
      }
      if ((int)puVar8[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x10))[1]) {
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar8);
        if (iVar7 != 0) {
          if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) goto LAB_005d47a8;
          goto LAB_005d43e4;
        }
        goto LAB_005d4744;
      }
      if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) {
LAB_005d47a8:
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar9);
        if (iVar7 == 0) goto LAB_005d4744;
        if ((int)puVar10[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x18))[1]) goto LAB_005d47d0;
LAB_005d43fc:
        iVar7 = piVar11[2];
      }
      else {
LAB_005d43e4:
        if ((int)(*(undefined4 **)((int)pcVar16 + 0x18))[1] <= (int)puVar10[2]) goto LAB_005d43fc;
LAB_005d47d0:
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar10);
        if (iVar7 == 0) goto LAB_005d4744;
        iVar7 = piVar11[2];
      }
      if ((iVar7 < 0x28) && (iVar7 = (*(code *)PTR_bn_expand2_006a9680)(piVar11,0x28), iVar7 == 0))
      goto LAB_005d4744;
      uStack_7e0 = 3;
      uStack_7dc = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0xc),*puVar2);
      uStack_7d8 = *puVar2;
      uStack_7d4 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x10),*puVar8);
      uStack_7d0 = *puVar8;
      uStack_7cc = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x14),*puVar9);
      uStack_7c8 = *puVar9;
      uStack_7c4 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x18),*puVar10)
      ;
      uStack_7c0 = *puVar10;
      iVar7 = (*(code *)p_CSwift_AttachKeyParam)(uStack_7f0,&uStack_7e0);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3d7;
        goto LAB_005d4718;
      }
      if (iVar7 == 0) {
        iStack_7a8 = *piVar11;
        puStack_7b4 = (undefined4 *)pcStack_764;
        uStack_7ac = 0x28;
        iStack_7b0 = iVar1;
        (*(code *)PTR_memset_006aab00)(iStack_7a8,0,0x28);
        iVar1 = iStack_7a8;
        puVar2 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x14);
        iVar1 = iStack_7a8;
        puVar2 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x28);
        uStack_7e8 = 4;
        piStack_7e4 = &iStack_7ec;
        iVar7 = (*(code *)p_CSwift_SimpleRequest)(uStack_7f0,4,&puStack_7b4,2,&uStack_7e8,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar6 = 0x3f2;
          goto LAB_005d4698;
        }
        puVar2 = (undefined4 *)(uint)(iStack_7ec != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar6 = 0x3dc;
LAB_005d4698:
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006aaa40)(auStack_7a4,1,0xd,&DAT_0066fa48,iVar7);
        puVar2 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",auStack_7a4);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_7f0);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    puVar2 = (undefined4 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(iVar3);
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar3);
LAB_005d45fc:
  if (iStack_794 == *(int *)puVar4) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 != 0) {
    iVar3 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"cswift");
    if (((((iVar3 != 0) &&
          (iVar3 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                             (iVar1,"CryptoSwift hardware engine support"), iVar3 != 0)) &&
         (iVar3 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,cswift_rsa), iVar3 != 0)) &&
        (((iVar3 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,cswift_dsa), iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,cswift_dh), iVar3 != 0)) &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,cswift_random), iVar3 != 0 &&
          ((iVar3 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,cswift_destroy),
           iVar3 != 0 &&
           (iVar3 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,cswift_init), iVar3 != 0)
           ))))))) &&
       ((iVar3 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,cswift_finish), iVar3 != 0
        && ((iVar3 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,cswift_ctrl), iVar3 != 0
            && (iVar3 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,cswift_cmd_defns),
               iVar3 != 0)))))) {
      iVar3 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar3 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar3 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar3 + 8);
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      if (CSWIFT_error_init != 0) {
        CSWIFT_error_init = 0;
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_functs);
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
        CSWIFT_lib_name._0_4_ = CSWIFT_lib_error_code << 0x18;
        (*(code *)PTR_ERR_load_strings_006a9564)(0,CSWIFT_lib_name);
      }
      (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d4b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar2 = (undefined4 *)(*(code *)PTR_ERR_clear_error_006a7fe0)();
      return puVar2;
    }
                    /* WARNING: Could not recover jumptable at 0x005d4954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar2 = (undefined4 *)(*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
    return puVar2;
  }
  return (undefined4 *)0x0;
}
