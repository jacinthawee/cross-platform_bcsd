
void UI_free(UI *ui)

{
  if (ui != (UI *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(*(undefined4 *)(ui + 4),free_string);
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xb,ui,ui + 0xc);
                    /* WARNING: Could not recover jumptable at 0x005b3784. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(ui);
    return;
  }
  return;
}

