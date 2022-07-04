#include "imgui.h"

#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"
#include "Walnut/Random.h"
#include "Walnut/Timer.h"

class ExampleLayer : public Walnut::Layer
{
public:
	~ExampleLayer()
	{
		if (m_ImageData)
		{
			delete[] m_ImageData;
		}
	}

	virtual void OnUIRender() final override
	{
		ImGui::Begin("Settings");

		ImGui::Text("Last render took %.3f ms", m_LastRenderTime);
		m_ShouldRender |= ImGui::Button("Render");

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
		ImGui::Begin("Viewport");

		const auto ContentRegionAvail = ImGui::GetContentRegionAvail();
		m_ShouldResize |= (ContentRegionAvail.x != m_ViewportWidth) ||
		                  (ContentRegionAvail.y != m_ViewportHeight);
		m_ViewportWidth = ContentRegionAvail.x;
		m_ViewportHeight = ContentRegionAvail.y;

		if (m_ShouldRender || m_ShouldResize)
		{
			if (m_ShouldResize)
			{
				if (m_ImageData)
				{
					delete[] m_ImageData;
				}
				m_ImageData = new uint32_t[m_ViewportWidth * m_ViewportHeight];
				m_Image.Resize(m_ViewportWidth, m_ViewportHeight);

				m_ShouldResize = false;
			}

			Walnut::Timer timer;

			for (uint32_t y = 0; y < m_Image.GetHeight(); y++)
			{
				for (uint32_t x = 0; x < m_Image.GetWidth(); x++)
				{
					m_ImageData[x + y * m_Image.GetWidth()] =
						Walnut::Random::UInt() | 0xff000000;
				}
			}
			m_Image.SetData(m_ImageData);

			m_LastRenderTime = timer.ElapsedMillis();
			m_ShouldRender = false;
		}

		ImGui::Image(m_Image.GetDescriptorSet(), { (float)m_Image.GetWidth(), (float)m_Image.GetHeight() },
				ImVec2(0, 1), ImVec2(1, 0));

		ImGui::End();
		ImGui::PopStyleVar();
	}

private:
	Walnut::Image m_Image {0, 0, Walnut::ImageFormat::RGBA};
	uint32_t* m_ImageData {nullptr};
	bool m_ShouldRender {true};
	bool m_ShouldResize {true};
	uint32_t m_ViewportWidth {};
	uint32_t m_ViewportHeight {};
	float m_LastRenderTime {};
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Ray Tracing";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}
