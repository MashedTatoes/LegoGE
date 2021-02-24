
#include "Mesh.h"
namespace LGE {
	
	Mesh::Mesh(size_t numVertices, size_t numIndices )
	{
		
		m_vertices = new Vertex[numVertices];
		m_indices = new unsigned int[numIndices];
		m_indicesSize = numIndices;
		m_verticesSize = numVertices;
	}

	Mesh::~Mesh()
	{
		delete[] m_vertices;
		delete[] m_indices;
		m_vertices = nullptr;
		m_indices = nullptr;
		
	}

	void Mesh::SetVertex(Vertex v, size_t index) {
		m_vertices[index] = v;

	}

	void Mesh::SetColor(unsigned int* vertices,int amount, LGEColor clr)
	{
		for (int i = 0; i < amount;i++)
		{
			m_vertices[vertices[i]].clr = clr;
		}

	}

	void Mesh::SetIndexBuffer(unsigned int* buffer)
	{
		m_indices = buffer;


	}
	float* Mesh::SerialzeToBuffer(size_t* bufferSize)
	{
		size_t size = LGE_2DVERTEX_SIZE * m_verticesSize;
		float *out = new float[size];
		*bufferSize = size;
		for (int i = 0; i < m_verticesSize; i++) {
			Vertex v = m_vertices[i];
			out[(i * LGE_2DVERTEX_SIZE) + 0] = ((v.x * m_transform->GetSize().x) *m_transform->GetScale().x) + m_transform->GetPosition().x;
			out[(i * LGE_2DVERTEX_SIZE) + 1] = ((v.y * m_transform->GetSize().y) * m_transform->GetScale().y) + m_transform->GetPosition().y;
			out[(i * LGE_2DVERTEX_SIZE) + 2] = v.tex_x;
			out[(i * LGE_2DVERTEX_SIZE) + 3] = v.tex_y;
			out[(i * LGE_2DVERTEX_SIZE) + 4] = v.clr.r;
			out[(i * LGE_2DVERTEX_SIZE) + 5] = v.clr.g;
			out[(i * LGE_2DVERTEX_SIZE) + 6] = v.clr.b;
			out[(i * LGE_2DVERTEX_SIZE) + 7] = v.clr.a;
		}
		return out;

	}

	void Mesh::LoadIntoVertexBuffer(VertexBuffer* buffer, unsigned int offset)
	{
		size_t size;
		float* vertices = SerialzeToBuffer(&size);
		m_offset = buffer->BufferData(vertices, size);

	}

	void Mesh::LoadIntoIndexBuffer(IndexBuffer* buffer, unsigned int offset)
	{
		buffer->BufferData(GetIndices(), GetNumIndices());

	}

	void Mesh::SetTexture(Texture* tex)
	{
		m_tex = tex;
	}

	Mesh* Mesh::quad()
	{
		
		Transform* t = new Transform(glm::vec3(0.0f), glm::vec3(100.0f));


		Mesh* quad = new Mesh(4,6,t);
		quad->SetIndexBuffer(new unsigned int[6]{ 0,1,2,2,3,0 });
		quad->SetVertex(Vertex(0, 0,0.0f,0.0f), 0); //Top left
		quad->SetVertex(Vertex(1, 0, 1.0f,0.0f), 1); //Top right
		quad->SetVertex(Vertex(1, 1,1.0f,1.0), 2); // Bottom right
		quad->SetVertex(Vertex(0, 1, 0.0f,1.0f), 3); //Bottom left
		return quad;
	}

	/*Mesh* Mesh::triangle()
	{
		Transform* t = new Transform(glm::vec3(300.0f), glm::vec3(150.0f));
		Mesh* triangle = new Mesh(3,3,t);
		triangle->SetIndexBuffer(new unsigned int[3]{ 0,1,2 });
		triangle->SetVertex(Vertex(1.0f, 1.0f, 0.0f,1.0f), 0);
		triangle->SetVertex(Vertex(0.5f, 0.5f, 0.0f,1.0f), 1);
		triangle->SetVertex(Vertex(1.5f, 0.5f, 0.0f,1.0f), 2);
		return triangle;
	}*/

	




}


