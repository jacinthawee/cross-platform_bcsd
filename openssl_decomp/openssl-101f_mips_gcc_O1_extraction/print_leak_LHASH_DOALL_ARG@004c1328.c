
void print_leak_LHASH_DOALL_ARG(CRYPTO_THREADID *param_1,CRYPTO_THREADID *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *pvVar3;
  CRYPTO_THREADID *pCVar4;
  int iVar5;
  CRYPTO_THREADID *b;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  CRYPTO_THREADID *unaff_s0;
  undefined *puVar9;
  CRYPTO_THREADID *unaff_s1;
  undefined *unaff_s2;
  CRYPTO_THREADID *unaff_s3;
  char *unaff_s4;
  char *unaff_s5;
  int unaff_s6;
  undefined4 unaff_s7;
  code *pcVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined4 unaff_s8;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    pvVar3 = param_1->ptr;
    puVar11 = &_gp;
    *(CRYPTO_THREADID **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00000074 + -8) = unaff_s8;
    *(undefined4 *)((int)register0x00000074 + -0xc) = unaff_s7;
    *(int *)((int)register0x00000074 + -0x10) = unaff_s6;
    *(undefined **)((int)register0x00000074 + -0x43c) = PTR___stack_chk_guard_006aabf0;
    *(char **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(char **)((int)register0x00000074 + -0x18) = unaff_s4;
    *(CRYPTO_THREADID **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(undefined **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(CRYPTO_THREADID **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x450) = &_gp;
    pCVar4 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
    pvVar1 = param_2->ptr;
    *(CRYPTO_THREADID **)((int)register0x00000074 + -0x2c) = pCVar4;
    unaff_s4 = &_ITM_registerTMCloneTable;
    b = param_2;
    unaff_s0 = param_1;
    if (pvVar3 != pvVar1) {
      if ((options & 1) == 0) {
        puVar9 = (undefined *)((int)register0x00000074 + -0x42c);
        iVar5 = 0x400;
      }
      else {
        puVar9 = (undefined *)((int)register0x00000074 + -0x42c);
        puVar2 = (undefined4 *)(*(code *)PTR_localtime_006aab40)(&param_1[3].val);
        uVar8 = puVar2[2];
        *(undefined4 *)((int)register0x00000074 + -0x454) = *puVar2;
        pcVar10 = *(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e80);
        *(undefined4 *)((int)register0x00000074 + -0x458) = puVar2[1];
        (*pcVar10)(puVar9,0x400,"[%02d:%02d:%02d] ",uVar8);
        iVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0))(puVar9);
        puVar11 = *(undefined **)((int)register0x00000074 + -0x450);
        puVar9 = puVar9 + iVar5;
        iVar5 = 0x400 - iVar5;
      }
      unaff_s1 = (CRYPTO_THREADID *)((int)register0x00000074 + -0x42c);
      pvVar1 = param_1[1].ptr;
      pvVar3 = param_1[3].ptr;
      pcVar10 = *(code **)(puVar11 + -0x7e80);
      *(ulong *)((int)register0x00000074 + -0x454) = param_1[1].val;
      *(void **)((int)register0x00000074 + -0x458) = pvVar1;
      (*pcVar10)(puVar9,iVar5,"%5lu file=%s, line=%d, ",pvVar3);
      iVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0))(puVar9);
      unaff_s2 = puVar9 + iVar5;
      puVar12 = *(undefined **)((int)register0x00000074 + -0x450);
      if ((options & 2) != 0) {
        uVar7 = CRYPTO_THREADID_hash(param_1 + 2);
        (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e80))
                  (unaff_s2,(int)unaff_s1 + (0x400 - (int)unaff_s2),"thread=%lu, ",uVar7);
        iVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0))(unaff_s2);
        puVar12 = *(undefined **)((int)register0x00000074 + -0x450);
        unaff_s2 = unaff_s2 + iVar5;
      }
      uVar7 = param_1->val;
      pcVar10 = *(code **)(puVar12 + -0x7e80);
      *(void **)((int)register0x00000074 + -0x458) = param_1->ptr;
      (*pcVar10)(unaff_s2,(int)unaff_s1 + (0x400 - (int)unaff_s2),"number=%d, address=%08lX\n",uVar7
                );
      b = unaff_s1;
      (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e88))(param_2->ptr);
      pCVar4 = (CRYPTO_THREADID *)param_1->val;
      pvVar1 = param_2[1].ptr;
      unaff_s0 = (CRYPTO_THREADID *)param_1[4].ptr;
      puVar11 = *(undefined **)((int)register0x00000074 + -0x450);
      param_2->val = param_2->val + 1;
      param_2[1].ptr = (void *)((int)pvVar1 + (int)pCVar4);
      unaff_s3 = param_2;
      if (unaff_s0 != (CRYPTO_THREADID *)0x0) {
        *(CRYPTO_THREADID **)((int)register0x00000074 + -0x440) =
             (CRYPTO_THREADID *)((int)register0x00000074 + -0x434);
        CRYPTO_THREADID_cpy((CRYPTO_THREADID *)((int)register0x00000074 + -0x434),unaff_s0);
        unaff_s2 = (undefined *)0x0;
        puVar11 = *(undefined **)((int)register0x00000074 + -0x450);
        unaff_s5 = " thread=%lu, file=%s, line=%d, info=\"";
        unaff_s7 = 0x7d;
        unaff_s4 = "\"\n";
        do {
          unaff_s2 = unaff_s2 + 1;
          (**(code **)(puVar11 + -0x5448))(unaff_s1,0x3e,unaff_s2,0x400);
          unaff_s8 = 0x400;
          uVar7 = CRYPTO_THREADID_hash(unaff_s0);
          *(ulong *)((int)register0x00000074 + -0x454) = unaff_s0[1].val;
          pcVar10 = *(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e80);
          *(void **)((int)register0x00000074 + -0x458) = unaff_s0[1].ptr;
          (*pcVar10)(unaff_s2 + (int)&unaff_s1->ptr,0x400 - (int)unaff_s2,
                     " thread=%lu, file=%s, line=%d, info=\"",uVar7);
          unaff_s6 = (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0))(unaff_s1);
          pvVar1 = unaff_s0[2].ptr;
          pcVar10 = *(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0);
          *(void **)((int)register0x00000074 + -0x444) = pvVar1;
          iVar5 = (*pcVar10)(pvVar1);
          if (0x7d - unaff_s6 < iVar5) {
            (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x52ec))
                      ((int)&unaff_s1->ptr + unaff_s6,
                       *(undefined4 *)((int)register0x00000074 + -0x444));
            iVar6 = 899;
            puVar13 = *(undefined **)((int)register0x00000074 + -0x450);
            iVar5 = 0x7d;
          }
          else {
            (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e7c))
                      ((int)&unaff_s1->ptr + unaff_s6,
                       *(undefined4 *)((int)register0x00000074 + -0x444),0x400 - unaff_s6);
            iVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x53b0))(unaff_s1);
            puVar13 = *(undefined **)((int)register0x00000074 + -0x450);
            iVar6 = 0x400 - iVar5;
          }
          (**(code **)(puVar13 + -0x7e80))((int)&unaff_s1->ptr + iVar5,iVar6,"\"\n");
          pCVar4 = (CRYPTO_THREADID *)param_2->ptr;
          b = unaff_s1;
          (**(code **)(*(int *)((int)register0x00000074 + -0x450) + -0x7e88))();
          unaff_s0 = (CRYPTO_THREADID *)unaff_s0[2].val;
          puVar11 = *(undefined **)((int)register0x00000074 + -0x450);
          if (unaff_s0 == (CRYPTO_THREADID *)0x0) break;
          b = *(CRYPTO_THREADID **)((int)register0x00000074 + -0x440);
          pCVar4 = unaff_s0;
          iVar5 = CRYPTO_THREADID_cmp(unaff_s0,b);
          puVar11 = *(undefined **)((int)register0x00000074 + -0x450);
        } while (iVar5 == 0);
      }
    }
    if (*(int *)((int)register0x00000074 + -0x2c) == **(int **)((int)register0x00000074 + -0x43c)) {
      return;
    }
    unaff_retaddr = print_leak_LHASH_DOALL_ARG;
    (**(code **)(puVar11 + -0x5328))();
    param_1 = pCVar4;
    param_2 = b;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x468);
  } while( true );
}

