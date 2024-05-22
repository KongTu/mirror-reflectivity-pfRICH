#include "RiceStyle.h"
using namespace std;
void plotMirrorReflectivity(){
	
	TFile* ref_mirror_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_05_17_2024.root");
	TFile* evp_mirror_10_1_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_1.1_05_17_2024.root");
	TFile* evp_mirror_10_2_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_2_05_17_2024.root");
	TFile* evp_mirror_10_cut_1_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_cut_1_05_17_2024.root");
	TFile* evp_mirror_10_cut_2_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_cut_2_05_17_2024.root");
	TFile* evp_mirror_10_cut_3_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_cut_3_05_17_2024.root");
	TFile* evp_mirror_10_cut_4_measurement = new TFile("../reflectivity_test_results/Evaporation-10/reflectivity_45_degree_measurement_evap10_7x7_cut_4_05_17_2024.root");

	TH1D* h_ref_mirror[7];
	
	h_ref_mirror[0] = (TH1D*) ref_mirror_measurement->Get("h_ref_mirror");
	h_ref_mirror[1] = (TH1D*) evp_mirror_10_1_measurement->Get("h_ref_mirror");
	h_ref_mirror[2] = (TH1D*) evp_mirror_10_2_measurement->Get("h_ref_mirror");
	h_ref_mirror[3] = (TH1D*) evp_mirror_10_cut_1_measurement->Get("h_ref_mirror");
	h_ref_mirror[4] = (TH1D*) evp_mirror_10_cut_2_measurement->Get("h_ref_mirror");
	h_ref_mirror[5] = (TH1D*) evp_mirror_10_cut_3_measurement->Get("h_ref_mirror");
	h_ref_mirror[6] = (TH1D*) evp_mirror_10_cut_4_measurement->Get("h_ref_mirror");

	for(int i=1;i<7;i++){
		h_ref_mirror[i]->SetLineColor(i);
	}

	TCanvas* c1 = new TCanvas("c1","c1",600,600);
	gPad->SetTicks();
	gPad->SetLeftMargin(0.15);
	gPad->SetBottomMargin(0.13);
	gPad->SetRightMargin(0.01);
	gPad->SetLogx(0);
	
	double xmin_axis=200;
	double xmax_axis=610;
	double ymin_axis=0.5;
	double ymax_axis=1.02;
	//mid-rapidity ALICE data point can be seen if change the range to ~160 GeV
	TH1D* base1 = makeHist("base1", "", "Wavelength (nm)", "Reflectivity", 100,xmin_axis,xmax_axis,kBlack);
	base1->GetYaxis()->SetRangeUser(ymin_axis, ymax_axis);
	base1->GetXaxis()->SetTitleColor(kBlack);
	
	fixedFontHist1D(base1,1.1,1.3);
	base1->GetYaxis()->SetTitleSize(base1->GetYaxis()->GetTitleSize()*1.4);
	base1->GetXaxis()->SetTitleSize(base1->GetXaxis()->GetTitleSize()*1.4);
	base1->GetYaxis()->SetLabelSize(base1->GetYaxis()->GetLabelSize()*1.5);
	base1->GetXaxis()->SetLabelSize(base1->GetXaxis()->GetLabelSize()*1.5);
	base1->GetXaxis()->SetNdivisions(6,6,2);
	base1->GetYaxis()->SetNdivisions(6,6,2);
	base1->Draw("");
	
	h_ref_mirror[0]->SetMarkerStyle(24);
	h_ref_mirror[0]->Draw("Psame");
	
	h_ref_mirror[1]->Draw("same");
	h_ref_mirror[2]->Draw("same");
	h_ref_mirror[3]->Draw("same");
	h_ref_mirror[4]->Draw("same");
	h_ref_mirror[5]->Draw("same");
	h_ref_mirror[6]->Draw("same");

	TLegend *w8 = new TLegend(0.17,0.15,0.46,0.45);
	w8->SetLineColor(kWhite);
	w8->SetFillColor(0);
	w8->SetTextSize(19);
	w8->SetTextFont(45);
	w8->AddEntry(h_ref_mirror[0], " UV enhanced mirror (THORLAB)", "P");
	w8->AddEntry(h_ref_mirror[1], " pfRICH 7x7 #1", "L");
	w8->AddEntry(h_ref_mirror[2], " pfRICH 7x7 #2", "L");
	w8->AddEntry(h_ref_mirror[3], " pfRICH 7x7 cut #1", "L");
	w8->AddEntry(h_ref_mirror[4], " pfRICH 7x7 cut #2", "L");
	w8->AddEntry(h_ref_mirror[5], " pfRICH 7x7 cut #3", "L");
	w8->AddEntry(h_ref_mirror[6], " pfRICH 7x7 cut #4", "L");
	w8->Draw("same");

	TLine* l1=new TLine(200,0.9,600,0.9);
	l1->SetLineStyle(2);
	l1->Draw("same");

	TLatex* r43 = new TLatex(0.18, 0.85, "Evaporation No.10 (05.17.2024)");
	r43->SetNDC();
	r43->SetTextSize(24);
	r43->SetTextFont(43);
	r43->SetTextColor(kBlack);
	r43->Draw("same");

	TLatex* r42 = new TLatex(0.77,0.91, "ePIC pfRICH");
	r42->SetNDC();
	r42->SetTextSize(0.04);
	r42->Draw("same");


	c1->Print("../figures/Evaporation-10.pdf");
	c1->Print("../figures/Evaporation-10.png");










}