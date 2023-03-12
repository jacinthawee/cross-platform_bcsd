
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint GetHostByName(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint in_t0;
  undefined1 *puVar23;
  uint uVar24;
  int iVar25;
  
  uVar24 = ghbn_cache._148_4_;
  if (((ghbn_cache._148_4_ == 0xffffffff) || (ghbn_cache._148_4_ != 0)) &&
     (iVar17 = (*(code *)PTR_strncmp_006a9970)(param_1,ghbn_cache,0x80), iVar17 == 0)) {
    iVar17 = 0;
  }
  else {
    uVar18 = uVar24;
    if (ghbn_cache._300_4_ < uVar24) {
      uVar18 = ghbn_cache._300_4_;
    }
    uVar24 = (uint)(ghbn_cache._300_4_ < uVar24);
    if ((ghbn_cache._300_4_ == 0) ||
       (iVar17 = (*(code *)PTR_strncmp_006a9970)(param_1,0x6aa9b0,0x80), iVar17 != 0)) {
      uVar19 = uVar18;
      if (ghbn_cache._452_4_ < uVar18) {
        uVar19 = ghbn_cache._452_4_;
      }
      if (ghbn_cache._452_4_ < uVar18) {
        uVar24 = 2;
      }
      if ((ghbn_cache._452_4_ == 0) ||
         (iVar17 = (*(code *)PTR_strncmp_006a9970)(param_1,0x6aaa48,0x80), iVar17 != 0)) {
        if (ghbn_cache._604_4_ < uVar19) {
          uVar24 = 3;
        }
        if ((ghbn_cache._604_4_ == 0) ||
           (iVar17 = (*(code *)PTR_strncmp_006a9970)(param_1,0x6aaae0,0x80), iVar17 != 0)) {
          ghbn_miss = ghbn_miss + 1;
          uVar18 = (*(code *)PTR_gethostbyname_006a9960)(param_1);
          if (uVar18 == 0) {
            uVar18 = 0;
          }
          else {
            uVar19 = (*(code *)PTR_strlen_006a9a24)(param_1);
            if (uVar19 < 0x80) {
              uVar22 = 0x80;
              uVar19 = uVar19 + 1;
              iVar25 = uVar24 * 0x98;
              puVar23 = ghbn_cache + iVar25;
              iVar20 = (*(code *)PTR___memcpy_chk_006a9a48)();
              uVar24 = uVar18 & 3;
              uVar1 = uVar18 + 4 & 3;
              iVar17 = *(int *)((uVar18 + 4) - uVar1);
              uVar2 = uVar18 + 8 & 3;
              iVar5 = *(int *)((uVar18 + 8) - uVar2);
              uVar3 = uVar18 + 0xc & 3;
              iVar6 = *(int *)((uVar18 + 0xc) - uVar3);
              uVar4 = uVar18 + 0x10 & 3;
              iVar7 = *(int *)((uVar18 + 0x10) - uVar4);
              uVar8 = uVar18 + 3 & 3;
              uVar9 = uVar18 + 7 & 3;
              uVar13 = *(uint *)((uVar18 + 7) - uVar9);
              uVar10 = uVar18 + 0xb & 3;
              uVar14 = *(uint *)((uVar18 + 0xb) - uVar10);
              iVar21 = ghbn_miss + ghbn_hits;
              uVar11 = uVar18 + 0xf & 3;
              uVar15 = *(uint *)((uVar18 + 0xf) - uVar11);
              uVar12 = uVar18 + 0x13 & 3;
              uVar16 = *(uint *)((uVar18 + 0x13) - uVar12);
              *(uint *)(ghbn_cache + iVar25 + 0x80) =
                   (*(int *)(uVar18 - uVar24) << uVar24 * 8 |
                   in_t0 & 0xffffffffU >> (4 - uVar24) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((uVar18 + 3) - uVar8) >> (3 - uVar8) * 8;
              *(uint *)(ghbn_cache + iVar25 + 0x84) =
                   (iVar17 << uVar1 * 8 | uVar22 & 0xffffffffU >> (4 - uVar1) * 8) &
                   -1 << (uVar9 + 1) * 8 | uVar13 >> (3 - uVar9) * 8;
              *(uint *)(ghbn_cache + iVar25 + 0x88) =
                   (iVar5 << uVar2 * 8 | uVar19 & 0xffffffffU >> (4 - uVar2) * 8) &
                   -1 << (uVar10 + 1) * 8 | uVar14 >> (3 - uVar10) * 8;
              *(uint *)(ghbn_cache + iVar25 + 0x8c) =
                   (iVar6 << uVar3 * 8 | param_1 & 0xffffffffU >> (4 - uVar3) * 8) &
                   -1 << (uVar11 + 1) * 8 | uVar15 >> (3 - uVar11) * 8;
              *(uint *)(ghbn_cache + iVar25 + 0x90) =
                   (iVar7 << uVar4 * 8 | (uint)puVar23 & 0xffffffffU >> (4 - uVar4) * 8) &
                   -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
              *(int *)(iVar20 + 0x94) = iVar21;
            }
          }
          return uVar18;
        }
        iVar17 = 3;
      }
      else {
        iVar17 = 2;
      }
    }
    else {
      iVar17 = 1;
    }
  }
  ghbn_hits = ghbn_hits + 1;
  *(int *)(ghbn_cache + iVar17 * 0x98 + 0x94) = ghbn_miss + ghbn_hits;
  return iVar17 * 0x98 + 0x6aa998;
}

