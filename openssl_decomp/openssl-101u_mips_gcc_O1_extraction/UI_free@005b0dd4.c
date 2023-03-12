
void UI_free(UI *ui)

{
  if (ui != (UI *)0x0) {
    (*(code *)PTR_sk_pop_free_006a7058)(*(undefined4 *)(ui + 4),free_string);
    (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0xb,ui,ui + 0xc);
                    /* WARNING: Could not recover jumptable at 0x005b0e34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(ui);
    return;
  }
  return;
}

