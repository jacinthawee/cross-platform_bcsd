
undefined4 rand_main(undefined4 param_1,int param_2)

{
  byte **ppbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  byte **ppbVar12;
  undefined4 uVar13;
  undefined *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *local_1048;
  byte *local_1040;
  int local_1030;
  undefined local_102c [4096];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  puVar5 = PTR_bio_err_006a6e3c;
  local_1030 = -1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar11 = *(int *)puVar5;
  if (iVar11 == 0) {
    uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar11 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
    *(int *)puVar5 = iVar11;
    if (iVar11 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar11 = *(int *)puVar5;
    }
  }
  iVar11 = load_config(iVar11,0);
  if (iVar11 != 0) {
    local_1048 = (byte *)0x0;
    bVar3 = false;
    bVar4 = false;
    local_1040 = (byte *)0x0;
    iVar11 = 0;
    pbVar15 = (byte *)0x0;
LAB_0046f974:
    do {
      ppbVar12 = (byte **)(param_2 + (iVar11 + 1) * 4);
      pbVar16 = *ppbVar12;
      iVar7 = iVar11 + 1;
      iVar9 = iVar11;
      while( true ) {
        iVar11 = iVar7;
        if (pbVar16 == (byte *)0x0) {
          bVar2 = false;
          goto joined_r0x0046fbd4;
        }
        iVar7 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,&DAT_00632514);
        if (iVar7 == 0) {
          if ((ppbVar12[1] == (byte *)0x0) || (pbVar15 != (byte *)0x0)) goto LAB_0046f9bc;
          iVar11 = iVar9 + 2;
          pbVar15 = ppbVar12[1];
          goto LAB_0046f974;
        }
        iVar7 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-engine");
        if (iVar7 != 0) break;
        ppbVar1 = ppbVar12 + 1;
        if ((*ppbVar1 == (byte *)0x0) || (local_1048 != (byte *)0x0)) goto LAB_0046f9bc;
        ppbVar12 = (byte **)(param_2 + (iVar9 + 3) * 4);
        pbVar16 = *ppbVar12;
        iVar7 = iVar9 + 3;
        iVar9 = iVar9 + 2;
        local_1048 = *ppbVar1;
      }
      iVar7 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-rand");
      if (iVar7 == 0) {
        if ((ppbVar12[1] == (byte *)0x0) || (local_1040 != (byte *)0x0)) goto LAB_0046f9bc;
        iVar11 = iVar9 + 2;
        local_1040 = ppbVar12[1];
        goto LAB_0046f974;
      }
      iVar9 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-base64");
      if (iVar9 == 0) {
        if (bVar4) goto LAB_0046f9bc;
        bVar4 = true;
      }
      else {
        iVar9 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,&DAT_00633928);
        if (iVar9 == 0) {
          bVar2 = true;
          if (bVar3) goto LAB_0046fbe0;
          bVar3 = true;
        }
        else {
          piVar10 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
          if (((((*(ushort *)(*piVar10 + (uint)*pbVar16 * 2) & 8) == 0) || (-1 < local_1030)) ||
              (iVar9 = (*(code *)PTR___isoc99_sscanf_006a9a04)(pbVar16,"%d",&local_1030), iVar9 == 0
              )) || (local_1030 < 0)) goto LAB_0046f9bc;
        }
      }
    } while( true );
  }
LAB_0046fc98:
  uVar8 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
LAB_0046fcac:
  if (local_2c != *(int *)puVar6) {
    uVar8 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return uVar8;
  }
  return uVar8;
LAB_0046f9bc:
  bVar2 = true;
joined_r0x0046fbd4:
  if (bVar3) {
LAB_0046fbe0:
    if (!bVar4) goto LAB_0046f9c8;
  }
  else {
LAB_0046f9c8:
    if ((-1 < local_1030) && (!bVar2)) {
      setup_engine(*(undefined4 *)puVar5,local_1048,0);
      app_RAND_load_file(0,*(undefined4 *)puVar5,local_1040 != (byte *)0x0);
      if (local_1040 != (byte *)0x0) {
        uVar13 = *(undefined4 *)PTR_bio_err_006a6e3c;
        uVar8 = app_RAND_load_files(local_1040);
        (*(code *)PTR_BIO_printf_006a6e38)(uVar13,"%ld semi-random bytes loaded\n",uVar8);
      }
      uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      iVar11 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
      if (iVar11 == 0) goto LAB_0046fc98;
      if (pbVar15 == (byte *)0x0) {
        iVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)
                          (iVar11,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
      }
      else {
        iVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6c,5,pbVar15);
      }
      if (iVar9 < 1) {
LAB_0046fe6c:
        uVar8 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
      }
      else {
        if (bVar4) {
          uVar8 = (*(code *)PTR_BIO_f_base64_006a74bc)();
          iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
          if (iVar9 == 0) goto LAB_0046fe6c;
          iVar11 = (*(code *)PTR_BIO_push_006a74c4)(iVar9,iVar11);
        }
        if (0 < local_1030) {
          do {
            while( true ) {
              iVar9 = local_1030;
              if (0x1000 < local_1030) {
                iVar9 = 0x1000;
              }
              iVar7 = (*(code *)PTR_RAND_bytes_006a7574)(local_102c,iVar9);
              if (iVar7 < 1) {
                uVar8 = 1;
                goto LAB_0046fb5c;
              }
              iVar7 = 0;
              puVar14 = local_102c;
              if (!bVar3) break;
              do {
                iVar7 = iVar7 + 1;
                (*(code *)PTR_BIO_printf_006a6e38)(iVar11,&DAT_006338a8,*puVar14);
                puVar14 = puVar14 + 1;
              } while (iVar7 < iVar9);
              local_1030 = local_1030 - iVar9;
              if (local_1030 < 1) goto LAB_0046fb20;
            }
            (*(code *)PTR_BIO_write_006a6e14)(iVar11,local_102c,iVar9);
            local_1030 = local_1030 - iVar9;
          } while (0 < local_1030);
        }
LAB_0046fb20:
        if (bVar3) {
          (*(code *)PTR_BIO_puts_006a6f58)(iVar11,"\n");
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0xb,0,0);
        uVar8 = 0;
        app_RAND_write_file(0,*(undefined4 *)puVar5);
LAB_0046fb5c:
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
        if (iVar11 == 0) goto LAB_0046fcac;
      }
      (*(code *)PTR_BIO_free_all_006a6e74)(iVar11);
      goto LAB_0046fcac;
    }
  }
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"Usage: rand [options] num\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"where options are\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar5,"-out file             - write to file\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar5,
             "-engine e             - use engine e, possibly a hardware device.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar5,"-rand file%cfile%c... - seed PRNG from files\n",0x3a,0x3a);
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar5,"-base64               - base64 encode output\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar5,"-hex                  - hex encode output\n");
  goto LAB_0046fc98;
}

