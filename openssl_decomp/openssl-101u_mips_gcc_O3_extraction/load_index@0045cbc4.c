
undefined4 * load_index(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  int local_128;
  undefined auStack_124 [256];
  int *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
  local_128 = -1;
  if (iVar4 == 0) {
    puVar8 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
    goto LAB_0045cd74;
  }
  iVar5 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6c,3,param_1);
  if (iVar5 < 1) {
    (*(code *)PTR_perror_006a9a80)(param_1);
    puVar8 = (undefined4 *)0x0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"unable to open \'%s\'\n",param_1);
  }
  else {
    iVar5 = (*(code *)PTR_TXT_DB_read_006a7bf0)(iVar4,6);
    if (iVar5 == 0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_124,0x100,"%s.attr",param_1);
      iVar6 = (*(code *)PTR_NCONF_new_006a6e58)(0);
      iVar7 = (*(code *)PTR_NCONF_load_006a6e5c)(iVar6,auStack_124,&local_128);
      iVar11 = iVar6;
      if (iVar7 < 1) {
        if (local_128 < 1) {
          iVar11 = 0;
          (*(code *)PTR_NCONF_free_006a6e6c)(iVar6);
          goto LAB_0045ccc8;
        }
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,
                   "error on line %ld of db attribute file \'%s\'\n",local_128,auStack_124);
      }
      else {
LAB_0045ccc8:
        puVar8 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"apps.c",0x6f0);
        if (puVar8 != (undefined4 *)0x0) {
          puVar8[1] = iVar5;
          if (param_2 == (undefined4 *)0x0) {
            *puVar8 = 1;
          }
          else {
            *puVar8 = *param_2;
          }
          if (iVar11 == 0) goto LAB_0045cd64;
          pcVar9 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(iVar11,0,"unique_subject");
          if (pcVar9 != (char *)0x0) {
            cVar1 = *pcVar9;
            if (cVar1 != 'N') {
              if (cVar1 < 'O') {
                if ((cVar1 != '0') && (cVar1 != 'F')) goto LAB_0045cd50;
              }
              else if ((cVar1 != 'f') && (cVar1 != 'n')) {
LAB_0045cd50:
                *puVar8 = 1;
                goto LAB_0045cd54;
              }
            }
            *puVar8 = 0;
          }
LAB_0045cd54:
          (*(code *)PTR_NCONF_free_006a6e6c)(iVar11);
          goto LAB_0045cd64;
        }
        (*(code *)PTR_fwrite_006a9a74)("Out of memory\n",1,0xe,*(undefined4 *)PTR_stderr_006a9af8);
        iVar6 = iVar11;
      }
      if (iVar6 != 0) {
        (*(code *)PTR_NCONF_free_006a6e6c)(iVar6);
      }
      puVar8 = (undefined4 *)0x0;
      (*(code *)PTR_TXT_DB_free_006a7bf4)(iVar5);
    }
  }
LAB_0045cd64:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar4);
LAB_0045cd74:
  if (local_24 == *(int **)puVar2) {
    return puVar8;
  }
  piVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar8 = (undefined4 *)
           (*(code *)PTR_TXT_DB_create_index_006a7bf8)
                     (piVar10[1],3,0,index_serial_LHASH_HASH,index_serial_LHASH_COMP);
  if (puVar8 == (undefined4 *)0x0) {
    iVar4 = piVar10[1];
    pcVar9 = "error creating serial number index:(%ld,%ld,%ld)\n";
  }
  else {
    if ((*piVar10 == 0) ||
       (puVar8 = (undefined4 *)
                 (*(code *)PTR_TXT_DB_create_index_006a7bf8)
                           (piVar10[1],5,index_name_qual,index_name_LHASH_HASH,index_name_LHASH_COMP
                           ), puVar8 != (undefined4 *)0x0)) {
      return (undefined4 *)0x1;
    }
    iVar4 = piVar10[1];
    pcVar9 = "error creating name index:(%ld,%ld,%ld)\n";
  }
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,pcVar9,*(undefined4 *)(iVar4 + 0x10),
             *(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18));
  return puVar8;
}

