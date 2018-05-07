using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InteractToken : MonoBehaviour
{
	public Camera unitCamera;
	public GameObject devPointer;
	public Material lineMat;
	private GameObject selectedObject;
	private ArrayList movementList;
	private GameObject movementLine;
	private LineRenderer line;

	void Start ()
	{
		selectedObject = null;
		movementList = new ArrayList();
		movementLine = new GameObject();
		line = movementLine.AddComponent<LineRenderer>();
		line.startWidth = .2f;
		line.endWidth = .2f;
		line.material = lineMat;
		line.positionCount = 0;
	}
	
	void Update ()
	{
		if (Input.GetMouseButtonDown(0))
		{
			Ray ray = unitCamera.ScreenPointToRay(new Vector3(Input.mousePosition.x, Input.mousePosition.y, 0));
			LayerMask selectionMask = 1 << 8;
			RaycastHit hit = new RaycastHit();
			if (Physics.Raycast(ray, out hit, 1000f, selectionMask))
			{
				if (selectedObject == null)
				{
					selectedObject = hit.transform.gameObject;
					line.positionCount++;
					line.SetPosition(0, selectedObject.transform.position);
				}
				else
				{
					if (hit.transform.gameObject.name == "DevDeselect")
					{
						selectedObject = null;
						movementList.Clear();
						line.positionCount = 0;
					}
					else
						selectedObject = hit.transform.gameObject;
				}
			}
			else
			{
				if (selectedObject != null)
				{
					LayerMask levelMask = 1 << 9;
					if (Physics.Raycast(ray, out hit, 1000f, levelMask))
					{
						GameObject movementPointer = new GameObject("Move" + line.positionCount);
						movementPointer.transform.position = hit.point + new Vector3(0, 2f);
						movementList.Add(movementPointer);
						line.positionCount++;
						line.SetPosition(line.positionCount - 1, hit.point + new Vector3(0, .1f));
					}
				}
			}
		}

		if (selectedObject != null)
		{
			devPointer.transform.position = selectedObject.transform.position + new Vector3(0, 2f);
		}
		else
		{
			devPointer.transform.position = new Vector3(0, -5f);
		}
	}

	void drawMovementPointer(Vector3 position)
	{

	}
}
